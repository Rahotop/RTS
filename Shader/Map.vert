#version 450 core

in vec3 in_Vertex;
in int gl_InstanceID;

layout (location = 0) uniform mat4 projection;
layout (location = 1) uniform mat4 modelview;
layout (location = 2) uniform uint offsetX;
layout (location = 3) uniform uint offsetY;
layout (location = 4) uniform int selectX;
layout (location = 5) uniform int selectY;

uniform param
{
	uint c[400];
};

out vec4 v_color;

void main()
{
	uint tmpY = gl_InstanceID%int(100)*2;
	uint tmpX = uint((gl_InstanceID)/100)*2;
	uint z = c[gl_InstanceID]%256;
	v_color = vec4(c[gl_InstanceID] >> 24, ((c[gl_InstanceID] << 8) >> 24), ((c[gl_InstanceID] << 16) >> 24), 1.0);
	
	if((tmpX + offsetX) == selectX*2 && (tmpY + offsetY) == selectY*2)
	 v_color = vec4(210.0,77.0,87.0,1.0);
	 
	gl_Position = projection * modelview * vec4(in_Vertex.x + tmpX + offsetX, in_Vertex.y + tmpY + offsetY, in_Vertex.z*z, 1.0);
}
