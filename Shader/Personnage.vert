#version 450 core

layout (location = 0) in vec3 in_Vertex;
layout (location = 1) in vec3 in_Color;

in int gl_InstanceID;

layout (location = 0) uniform mat4 projection;
layout (location = 1) uniform mat4 modelview;
layout (location = 2) uniform float posX;
layout (location = 3) uniform float posY;
layout (location = 4) uniform uint posZ;

out vec4 v_color;

void main()
{/*
	uint tmpX = pos[gl_InstanceID]>>20;
	uint tmpY = ((pos[gl_InstanceID]<<12)>>20);
	uint tmpZ = pos[gl_InstanceID]%256
	
	uint tmpX = position >> 20;
	uint tmpY = (position << 12) >> 20;
	uint tmpZ = position % 256;*/
	
	float tmpX = posX;
	float tmpY = posY;
	uint tmpZ = posZ;
	
	gl_Position = projection * modelview * vec4(in_Vertex.x + tmpX*2, in_Vertex.y + tmpY*2, in_Vertex.z + tmpZ, 1.0);
	v_color = vec4(in_Color,1.0);
}
