#version 330 core

in vec4 nv;

out vec4 outColor;

void main()
{
	outColor = abs(nv);
}
