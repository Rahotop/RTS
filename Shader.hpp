#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>

//Classe représentant un shader
class Shader
{
	public:
	
	//Constructeur qui prend en parametre les chemins vers le vertex shader et le fragment shader
	Shader(std::string vertexShader, std::string fragmentShader);
	~Shader();
	
	//Accesseur à l'id du shader
	GLuint getID();
	
	private:
	
	GLuint m_programID;
};

#endif
