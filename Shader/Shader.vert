#version 450 core

in vec3 in_Vertex;

layout (location = 0) uniform mat4 projection;
layout (location = 1) uniform mat4 modelview;

void main()
{/*
	vec4 vertices[3] = vec4[3](	vec4(0.25,-0.25,0.5,1.0),
								vec4(-0.25,-0.25,0.5,1.0),
								vec4(0.25,0.25,0.5,1.0));
	gl_Position = vertices[gl_VertexID];*/
	
	gl_Position = projection * modelview * vec4(in_Vertex, 1.0);
	
	//gl_Position = vec4(0.0,0.5,0.5,1.0);
}
