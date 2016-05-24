#ifndef CASE_HPP_INCLUDED
#define CASE_HPP_INCLUDED

#include <iostream>
//Bibliothèques nécessaires pour les types OpenGL
#include <GL/glew.h>
#include <GL/glut.h>

//Classe représentant une case sur la map
class Case
{
	public:
	
	//Constructeur par défaut
	Case();
	//Constructeur qui initialise la couleur avec les valeurs de r, v et b et la hauteur avec la valeur de h
	Case(unsigned int r, unsigned int v, unsigned int b, unsigned int h);
	//Constructeur par recopie
	Case(const Case& c);
	
	//Accesseur aux paramètres
	GLuint getPar();
	void setPar(unsigned int r, unsigned int v, unsigned int b, unsigned int h);
	
	//Surcharge de l'opérateur =
	Case& operator=(const Case& c);
	
	private:
	
	/*Paramètres de la case :
	1 octet pour la composante rouge de la case
	1 octet pour la composante verte de la case
	1 octet pour la composante bleue de la case
	1 octet pour la hauteur de la case
	4 octets au final les 32 bits du GLuint sont tous utilisés.
	Le nombre d'informations par bit est de 100%
	On garde la portabilité en utilisant 32 bits et non 64*/
	GLuint m_par;
};

#endif
