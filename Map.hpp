#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Objet.hpp"
#include "TableauCase.hpp"
#include "Cube.hpp"
#include "Shader.hpp"

class Map : public Objet
{
	public:
	
	Map();
	~Map();
	
	void afficher(glm::mat4 modelview, glm::mat4 projection);
	
	private:
	
	TableauCase *m_tabC;
	Shader m_shaderMap;
};

#endif
