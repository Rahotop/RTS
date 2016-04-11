#ifndef CASE_HPP_INCLUDED
#define CASE_HPP_INCLUDED

//Bibliothèques nécessaires pour les types OpenGL
#include <GL/glew.h>
#include <GL/glut.h>

//Classe représentant une case sur la map
class Case
{
	public:
	
	//Constructeur par défaut
	Case();
	//Constructeur qui initialise la position avec les valeurs de x et y
	Case(unsigned int x, unsigned int y);
	//Constructeur par recopie
	Case(const Case& c);
	
	//Accesseur de la position
	GLuint getPos();
	
	//Surcharge de l'opérateur =
	Case& operator=(const Case& c);
	
	private:
	
	//Position de la case sur deux axes 2 octet pour l'axe x, 2 octets pour l'axe y.
	GLuint m_pos;
};

#endif
