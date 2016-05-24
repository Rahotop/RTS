#ifndef INIT_HPP_INCLUDED
#define INIT_HPP_INCLUDED

#include <GL/glew.h>
#include <GL/glut.h>

class Init
{
	public:
	
	Init() : m_initGlew(0)
	{
		GLenum initGlew(glewInit()); //On initialise glew
		
		if(initGlew != GLEW_OK)
		    std::cout << "Error : Glew init failed" << std::endl;
		else
			std::cout << "glew init ok" << std::endl;

	}
	
	private:
	
	GLenum m_initGlew;
};

#endif
