#version 330 core

out vec4 outColor;

void main()
{
	vec2 c = vec2(1,0);

	outColor = vec4(1.0, 0.0, 0.0, 1.0);
	//outColor = (mod(gl_PrimitiveID, 2) == 0) ? c.xxyy : c.yyxx;
}
