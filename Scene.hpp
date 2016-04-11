#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"
#include "Cube.hpp"
#include "Event.hpp"
#include "Map.hpp"

class Scene : public sf::Window
{
	public:
	
	Scene(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings settings);
	~Scene();
	
	void boucle();
	void changeViewPort(int x, int y);
	
	private:
	
	glm::mat4 m_projection;
	glm::mat4 m_modelview;
	
	Event m_event;
};

#endif
