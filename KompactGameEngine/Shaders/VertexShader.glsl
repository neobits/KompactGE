// Vertex Shader

#version 430 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;

out vec4 color;

void main(void)
{
	color = in_color;
	gl_Position = vec4(in_position, 1);
}