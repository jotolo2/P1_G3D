#version 330 core
//OBLIGATORIO 4: DESCARTAR FRAGMENTO POR COORDENADAS DE TEXTURA

in vec2 tc;

out vec4 outColor;

uniform sampler2D colorTex;

void main()
{
	vec4 texColor = texture(colorTex, tc);
	if(texColor.rgb == vec3(0))
	{
		discard;
	}
	outColor = texColor;
}
