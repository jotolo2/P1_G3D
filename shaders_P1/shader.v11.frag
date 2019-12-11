#version 330 core

in vec2 tc;

out vec4 outColor;

uniform sampler2D colorTex;

void main()
{
    vec2 tc_aux = tc*3-1.5;
	if(pow((tc_aux.x * tc_aux.x + tc_aux.y * tc_aux.y -1),3)-( tc_aux.x * tc_aux.x * tc_aux.y * tc_aux.y *tc_aux.y)<0)
	//if (tc.s>0.5)
	{
	outColor = vec4(1,0,0,0);
	}
	else
	{
	outColor = vec4(0,1,0,0);
	}
}

