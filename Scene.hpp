#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <vector>
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
#include "Camera.hpp"
#include "Personnage.hpp"
#include "Init.hpp"

//Classe représentant une scene OpenGL dans une fenetre SFML
class Scene : public sf::RenderWindow
{
	public:
	
	//Constructeur qui prend en parametre la taille de la fenetre, le titre, le style et le contexte OpenGL
	Scene(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings settings);
	~Scene();
	
	//Boucle de rendu
	void boucle(Event *e);
	//Changer la résolution de la fenetre, utile en cas de redimensionnement
	void changeViewPort(int x, int y);
	
	Camera getCam();
	
	void addElem(int id, const Position& p, int c);
	void eraseElem(int id);
	void setElem(int id, const Position& p);
	
	int getGold();
	void setGold(int g);
		
	private:
	
	//Matrices utiles au rendu
	glm::mat4 m_projection;
	glm::mat4 m_modelview;
	
	//Camera
	Camera m_cam;
	
	//Initialisations
	
	Init m_init;
	
	//Objets
	
	Map m_map;
	std::vector<Personnage*> m_perso;
	
	int m_gold;
};

#endif
