#version 330 core

in vec3 inPos;

uniform mat4 model;

void main()
{
	mat4 view = mat4(1.0f);
	view[3].z = -6.0f;

	mat4 proj = mat4(0.0f);
	float n = 1.0f;
	float f = 10.0f;
	proj[0].x = 1 / tan(radians(30.0f));
	proj[1].y = 1 / tan(radians(30.0f));
	proj[2].z = -(f + n) / (f - n);
	proj[3].z = (-2.0f * f * n) / (f - n);
	proj[2].w = -1.0f;
	
	gl_Position = proj * view * model * vec4(inPos, 1.0);
}
