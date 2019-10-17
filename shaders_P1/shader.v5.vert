#version 330 core

in vec3 inPos;

out vec3 vColor;

uniform mat4 modelViewProj;

void main()
{
	vColor = inPos;
	gl_Position = modelViewProj * vec4(inPos,1.0);
}
