#ifndef PERSONNAGE_HPP_INCLUDED
#define PERSONNAGE_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#ifndef BUFFER_OFFSET

    #define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

#endif

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Objet.hpp"
#include "Shader.hpp"
#include "Position.hpp"
#include "Cube.hpp"
#include "Map.hpp"

class Personnage : public Objet
{

	public:
	
	Personnage();
	Personnage(std::string path);
	virtual ~Personnage();
	
	void setElem(int id, const Position& p);
	void eraseElem(int id);
	int count(int id);
	
	void afficher(glm::mat4 modelview, glm::mat4 projection);
	
	
	private:

	Shader m_shaderPerso;
	
	std::unordered_map<int, Position> m_mapPos;
	
	float *m_vertices;
	GLubyte *m_indices;
	float *m_color;
	GLuint m_vbo;
	GLuint m_ibo;
	int m_tailleI;
	GLuint m_bindingPoint;
	int m_offsetColor;
};

#endif
