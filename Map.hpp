#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include "Objet.hpp"
#include "TableauCase.hpp"
#include "Cube.hpp"
#include "Shader.hpp"
#include "Event.hpp"
#include "Position.hpp"

class Map : public Objet
{
	public:
	
	Map();
	Map(std::string path);
	~Map();
	
	//Methode d'affichage de la map
	void afficher(glm::mat4 modelview, glm::mat4 projection);
	
	void selectionFleche(Event& e);
	void update(Event& e);
	
	unsigned int getHauteur(int x, int y);
	
	private:
	
	TableauCase *m_tabC;
	Shader m_shaderMap;
	unsigned int m_x;
	unsigned int m_y;
	unsigned int m_nbTab;
	GLuint m_bindingPoint;
	
	Position m_cursor;
};

#endif
