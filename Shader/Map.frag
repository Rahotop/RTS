#version 450 core

layout (location = 2) uniform vec3 inColor;
out vec4 color;

void main()
{
	color = vec4(inColor, 1.0);
}
