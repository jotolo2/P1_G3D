#version 330 core

in vec2 tc;

out vec4 outColor;

uniform sampler2D colorTex;


void main()
{
	vec4 texColor= texture(colorTex, tc);
	if(texColor.rgb == vec3(0))
	{
		discard;
	}
	outColor = texColor;
}
