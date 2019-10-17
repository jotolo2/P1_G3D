#version 330 core

in vec3 inPos;
in vec2 inTexCoord;

out vec2 tc;

uniform mat4 modelViewProj;

void main()
{	
	tc = inTexCoord;
	gl_Position = modelViewProj*vec4(inPos,1.0) ;
}
