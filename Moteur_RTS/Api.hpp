#ifndef API_HPP_INCLUDED
#define API_HPP_INCLUDED

#include "Position.hpp"
#include "Gestionnaire.hpp"
#include "../Scene.hpp"
#include "../Event.hpp"
#include "Joueur.hpp"

class Element;

class Api
{
	public:
	
	Api(sf::ContextSettings settings);
	
	void boucle();
	
	void addElem(Element *e, int c);
	void eraseElem(int id);
	void setElem(int id, const Position& p);
	
	float getElapsedTime();
	
	private:
	
	Gestionnaire m_gestionnaire;
	Scene m_scene;
	Event m_event;
	
	Joueur m_j1;
};

#endif
