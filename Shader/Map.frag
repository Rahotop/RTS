#version 450 core

in vec4 gl_FragCoord;

in vec4 v_color;

out vec4 color;

void main()
{
	color = vec4(v_color.xyz/255.0, v_color.w);
}
