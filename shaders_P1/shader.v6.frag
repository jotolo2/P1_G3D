#version 330 core

in vec3 vColor;

out vec4 outColor;

void main()
{
	outColor = vColor.xyzz;
}
