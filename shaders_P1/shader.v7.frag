#version 330 core

in vec2 tc;

out vec4 outColor;

uniform sampler2D colorTex;

void main()
{
	outColor = texture(colorTex, tc);
}
