#include "BOX.h"
#include <IGL/IGlib.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


//Idenficadores de los objetos de la escena
int objId1 =-1;
int objId2 = -1;

//Vectores descriptores de la cámara para la matriz view
glm::mat4 view;
glm::vec3 cameraPos, cameraForward, cameraUp;

//Declaración de CB
void resizeFunc(int width, int height);
void idleFunc();
void keyboardFunc(unsigned char key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);


int main(int argc, char** argv)
{
	std::locale::global(std::locale("spanish")); // acentos ;)
	if (!IGlib::init("../shaders_P1/shader.v5.vert", "../shaders_P1/shader.v5.frag"))
		return -1;
   
	//CBs
	IGlib::setResizeCB(resizeFunc);
	IGlib::setIdleCB(idleFunc);
	IGlib::setKeyboardCB(keyboardFunc);
	IGlib::setMouseCB(mouseFunc);
  	IGlib::setMouseMoveCB(mouseMotionFunc);

	//Matriz de Vista
	cameraPos = glm::vec3(0.0f, 0.0f, -7.0f);
	cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
	cameraUp = glm::vec3(0, 1, 0);
	view = glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp);
	IGlib::setViewMat(view);

	//Matriz de proyección
	glm::mat4 proj = glm::mat4(0.0f);
	float n = 1.0f;
	float f = 50.0f;
	proj[0].x = 1 / tan(glm::radians(30.0f));
	proj[1].y = 1 / tan(glm::radians(30.0f));
	proj[2].z = -(f + n) / (f - n);
	proj[3].z = (-2.0f * f * n) / (f - n);
	proj[2].w = -1.0f;
	IGlib::setProjMat(proj);

	//Creamos el objeto que vamos a visualizar
	objId1 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
			cubeVertexPos, cubeVertexColor, cubeVertexNormal,cubeVertexTexCoord, cubeVertexTangent);

	objId2 = IGlib::createObj(cubeNTriangleIndex, cubeNVertex, cubeTriangleIndex,
		cubeVertexPos, cubeVertexColor, cubeVertexNormal, cubeVertexTexCoord, cubeVertexTangent);
		
	glm::mat4 modelMat = glm::mat4(1.0f);
	IGlib::setModelMat(objId1, modelMat);
	IGlib::setModelMat(objId2, modelMat);

	//Incluir texturas aquí.
	IGlib::addColorTex(objId1, "../img/color.png");
	
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
	//Ajusta el aspect ratio al tamaño de la venta
	glm::mat4 proj = glm::mat4(0.0f);
	float aspectRatio = width / height;
	float n = 1.0f;
	float f = 50.0f;

	proj[0].x = 1 / (tan(glm::radians(30.0f)) * aspectRatio);
	proj[1].y = 1 / tan(glm::radians(30.0f));
	proj[2].z = -(f + n) / (f - n);
	proj[3].z = (-2.0f * f * n) / (f - n);
	proj[2].w = -1.0f;

	IGlib::setProjMat(proj);
}

void idleFunc()
{
	static float ang = 0.0f;
	glm::mat4 model(1.0f);

	//Rotacion del primer cubo sobre si mismo
	ang = (ang < 6.2830f) ? ang + 0.01f : 0.0f;
	model = glm::rotate(model, ang, glm::vec3(1, 1, 0));
	IGlib::setModelMat(objId1, model);

	//Órbita del segundo cubo
	float r = 3.0f;
	float x = 0 + r * cos(ang);
	float z = 0 + r * sin(ang);
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, 0.0f, z));
	model = glm::rotate(model, ang*10.0f, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3(0.2));
	IGlib::setModelMat(objId2, model);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	std::cout << "Se ha pulsado la tecla " << key << std::endl << std::endl;
	glm::vec3 left;
	glm::vec4 result;
	glm::mat4 rotation;
	switch (key)
	{
	case('a'):
	case('A'):
		left = glm::normalize(glm::cross(cameraUp, cameraForward));
		cameraPos = cameraPos + left*0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('d'):
	case('D'):
		left = glm::normalize(glm::cross(cameraUp, cameraForward));
		cameraPos = cameraPos - left*0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('s'):
	case('S'):
		cameraPos = cameraPos - cameraForward*0.2f;
		IGlib::setViewMat(glm::lookAt(cameraPos, cameraPos + cameraForward, cameraUp));
		break;

	case('w'):
	case('W'):
		cameraPos = cameraPos + cameraForward*0.2f;
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
	if (state==0)
		std::cout << "Se ha pulsado el botón ";
	else
		std::cout << "Se ha soltado el botón ";
	
	if (button == 0) std::cout << "de la izquierda del ratón " << std::endl;
	if (button == 1) std::cout << "central del ratón " << std::endl;
	if (button == 2) std::cout << "de la derecha del ratón " << std::endl;

	std::cout << "en la posición " << x << " " << y << std::endl << std::endl;
}

void mouseMotionFunc(int x, int y)
{

}
