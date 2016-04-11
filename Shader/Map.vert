#version 450 core

in vec3 in_Vertex;
in int gl_InstanceID;

layout (location = 0) uniform mat4 projection;
layout (location = 1) uniform mat4 modelview;

uniform pos
{
	uint c[3];
};

void main()
{
	uint tmpX = (c[gl_InstanceID] >> 16)*2;
	uint tmpY = (c[gl_InstanceID]%65536)*2;
	int z = 12;
	
	gl_Position = projection * modelview * vec4(in_Vertex.x + tmpX, in_Vertex.y +tmpY, ((in_Vertex.z+1)*z)-1, 1.0);
}
