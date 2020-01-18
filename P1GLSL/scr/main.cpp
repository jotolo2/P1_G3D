#include "BOX.h"
#include "PYRAMID.h"
#include <IGL/IGlib.h>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

// Idenficadores de los objetos de la escena
int objId1 = -1;
int objId2 = -1;
int objId3 = -1;

bool firstCurve = true;

// Vectores descriptores de la cámara para la matriz view
glm::mat4 view;
glm::vec3 cameraPos, cameraForward, cameraUp;

// Control del movimiento del ratón
float x_pressed, y_pressed;
bool isPressed;

// Puntos de control de trayectoria
std::vector <glm::vec3> controlPoints;

//Declaración de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);

int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish")); // acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v11.vert", "../shaders_P1/shader.v11.frag"))
		return -1;

	//CBs
	IGlib::setResizeCB(resizeFunc);
	IGlib::setIdleCB(idleFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
	IGlib::setMouseMoveCB(mouseMotionFunc);

	//Matriz de Vista2
	cameraPos = glm::vec3(0.0f, 0.0f, -15.0f);
	cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	view = glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp);
	IGlib::setViewMat(view);

	//Matriz de proyección
	glm::mat4 proj = glm::mat4(0.0f);
	float near = 1.0f;
	float far = 50.0f;
	proj[0].x = 1.0f / tan(glm::radians(30.0f));
	proj[1].y = 1.0f / tan(glm::radians(30.0f));
	proj[2].z = -(far + near) / (far - near);
	proj[3].z = (-2.0f * far * near) / (far - near);
	proj[2].w = -1.0f;
	IGlib::setProjMat(proj);

	//Creamos el objeto que vamos a visualizar
	/*
	objId1 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);

	objId2 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);
		
	objId3 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);
	*/
	
	//OPTATIVA 4: CREAMOS NUEVO OBJETO DEFINIDO POR NOSOTROS MANUALMENTE
	objId1 = IGlib::createObj(pyramidNTriangleIndex, pyramidNVertex, pyramidTriangleIndex,
		pyramidVertexPos, pyramidVertexColor, pyramidVertexNormal, pyramidVertexTexCoord, pyramidVertexTangent);

	objId2 = IGlib::createObj(pyramidNTriangleIndex, pyramidNVertex, pyramidTriangleIndex,
		pyramidVertexPos, pyramidVertexColor, pyramidVertexNormal, pyramidVertexTexCoord, pyramidVertexTangent);

	objId3 = IGlib::createObj(pyramidNTriangleIndex, pyramidNVertex, pyramidTriangleIndex,
		pyramidVertexPos, pyramidVertexColor, pyramidVertexNormal, pyramidVertexTexCoord, pyramidVertexTangent);
		
	glm::mat4 modelMat = glm::mat4(1.0f);
	IGlib::setModelMat(objId1, modelMat);
	IGlib::setModelMat(objId2, modelMat);
	IGlib::setModelMat(objId3, modelMat);

	// Creacion de puntos de control
	glm::vec3 points[] = {
		glm::vec3(-4.5f,0.0f,0.0f), //P0
		glm::vec3(-1.5f,8.0f,10.0f), //P1
		glm::vec3(4.5f,8.0f,10.0f), //P2
		glm::vec3(4.5f,0.0f,0.0f), //P3
		glm::vec3(4.5f,-8.0f,-10.0f), //P4
		glm::vec3(-1.5f,-8.0f,-10.0f), //P5

	};
	controlPoints.insert(controlPoints.begin(), points, points + 6);

	//Incluir texturas aquí.
	//IGlib::addColorTex(objId1, "../img/color.png");
	IGlib::addColorTex(objId1, "../img/discardText.png");

	//CBs
	IGlib::setIdleCB(idleFunc);
	IGlib::setResizeCB(resizeFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);

	//Mainloop
	IGlib::mainLoop();
	IGlib::destroy();
	return 0;
}

void resizeFunc(int width, int height)
{
	//OBLIGATORIO 1: AJUSTE DEL ASPECT RATIO AL TAMAÑO DE LA VENTANA
	glm::mat4 proj = glm::mat4(0.0f);
	float aspectRatio = float(width) / float(height);
	float near = 1.0f;
	float far = 50.0f;
	float fov = 30.0f;

	proj[0].x = 1.0f / (tan(glm::radians(fov)) * aspectRatio);
	proj[1].y = 1.0f / tan(glm::radians(fov));
	proj[2].z = -(far + near) / (far - near);
	proj[3].z = (-2.0f * far * near) / (far - near);
	proj[2].w = -1.0f;

	IGlib::setProjMat(proj);
}

void idleFunc()
{
	static float ang = 0.0f;
	static float t = 0.0f;
	glm::mat4 model(1.0f);

	//Rotacion del primer cubo sobre si mismo
	ang = (ang < 6.2830f) ? ang + 0.01f : 0.0f;
	model = glm::rotate(model, ang, glm::vec3(1, 1, 0));
	IGlib::setModelMat(objId1, model);

	//OBLIGATORIO 2: ÓRBITA DEL SEGUNDO CUBO
	float r = 3.0f;
	float x = 0 + r * cos(ang);
	float z = 0 + r * sin(ang);
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, 0.0f, z));
	model = glm::rotate(model, ang * 10.0f, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3(0.2f));
	IGlib::setModelMat(objId2, model);

	//OPTATIVO 2: TRAYECTORIA DEL TERCER CUBO MEDIENATE 2 CURVAS DE BEZIER DE 3er GRADO
	model = glm::mat4(1.0f);
	glm::vec3 pos;
	if (t < 1.0f)
	{
		t = t + 0.01f;
	}
	else
	{
		t -= 1.0f;
		firstCurve = !firstCurve;
	}

	if (firstCurve) 
	{
		pos = std::pow((1 - t), 3) * controlPoints[0] + 3 * t * std::pow(1 - t, 2) * controlPoints[1]
			+ 3 * t * t * (1 - t) * controlPoints[2] + t * t * t * controlPoints[3];
	}	
	else
	{
		pos = std::pow((1 - t), 3) * controlPoints[3] + 3 * t * std::pow(1 - t, 2) * controlPoints[4]
			+ 3 * t * t * (1 - t) * controlPoints[5] + t * t * t * controlPoints[0];
	}
	model = glm::translate(model, glm::vec3(pos));

	IGlib::setModelMat(objId3, model);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	//std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
	//OBLIGATORIO 3: CONTROL DE LA CÁMARA POR TECLADO
	glm::vec3 left;
	glm::vec4 result;
	glm::mat4 rotation;
	switch (key)
	{
	case('a'):
	case('A'):
		left = glm::normalize(glm::cross(cameraUp, cameraForward));
		cameraPos = cameraPos + left * 0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('d'):
	case('D'):
		left = glm::normalize(glm::cross(cameraUp, cameraForward));
		cameraPos = cameraPos - left * 0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('s'):
	case('S'):
		cameraPos = cameraPos - cameraForward * 0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('w'):
	case('W'):
		cameraPos = cameraPos + cameraForward * 0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('z'):
	case('Z'):
		rotation = glm::rotate(glm::mat4(1.0f), 0.05f, glm::vec3(0, 1, 0));
		result = rotation * glm::vec4(cameraForward, 0.0f);
		cameraForward = glm::normalize(glm::vec3(result));
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('x'):
	case('X'):
		rotation = glm::rotate(glm::mat4(1.0f), -0.05f, glm::vec3(0, 1, 0));
		result = rotation * glm::vec4(cameraForward, 0.0f);
		cameraForward = glm::normalize(glm::vec3(result));
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	}
}

void mouseFunc(int button, int state, int x, int y)
{
	if (state == 0)
	{
		// Cuando se pulsa el botón izquierdo
		if (button == 0)
		{
			x_pressed = x;
			y_pressed = y;
			isPressed = true;
		}
	}
	else
	{
		isPressed = false;
	}

	//if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	//if (button == 1) std::cout << "central del ratón " << std::endl;
	//if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	//std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{
	if (isPressed)
	{
		//OPTATIVO 1: CONTROL DE LA CÁMARA POR RATÓN
		glm::vec3 left;
		glm::vec4 result;
		glm::mat4 horizontal_rotation, vertical_rotation;

		// Cálculo del ángulo mediante la diferencia de (raton - raton pulsado)
		float scale = 0.001f;
		float angle_x = (x - x_pressed) * scale;
		float angle_y = (y - y_pressed) * scale;

		left = glm::normalize(glm::cross(cameraForward, cameraUp));

		// Obtención de las rotaciones 
		horizontal_rotation = glm::rotate(glm::mat4(1.0f), angle_x, glm::vec3(0, 1, 0));
		vertical_rotation = glm::rotate(glm::mat4(1.0f), angle_y, left);

		// Aplicación de las rotaciones a los dos vectores que determinan la orientación de la cámara
		result = horizontal_rotation * vertical_rotation *   glm::vec4(cameraForward, 0.0f);
		cameraForward = glm::normalize(glm::vec3(result));

		result =  horizontal_rotation * vertical_rotation * glm::vec4(cameraUp, 0.0f);
		cameraUp = glm::normalize(glm::vec3(result));

		// Reseteamos la matriz de vista con la nueva orientación
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));

		x_pressed = x;
		y_pressed = y;
	}
}