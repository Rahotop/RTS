#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
//#include <SFML/OpenGL.hpp>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glew.h>
#include <GL/glut.h>

class Shader
{
	public:
	
	Shader(std::string vertexShader, std::string fragmentShader);
	~Shader();
	
	GLuint getID();
	
	private:
	
	GLuint m_programID;
};

#endif
