#include "Api.hpp"
#include "Element.hpp"

Api::Api(sf::ContextSettings settings) : m_gestionnaire(this), m_scene(sf::VideoMode(800, 600), "Tamer", sf::Style::Default, settings), m_event(&m_scene), m_j1()
{
	Player::setGestionnaire(&m_gestionnaire);
	m_j1.initPlayer(Position(1,1));
}

void Api::boucle()
{
	while(m_event.isRunning())
	{	
		m_event.update();
		m_gestionnaire.boucle(m_event);
		m_j1.boucle(m_event);
		m_scene.boucle(&m_event);
		m_scene.setGold(m_j1.getGold());
	}
}

void Api::addElem(Element *e, int c)
{
	m_scene.addElem(e->getId(), e->getPos(), c);
}

void Api::eraseElem(int id)
{
	m_j1.eraseElem(id);
	m_scene.eraseElem(id);
}

void Api::setElem(int id, const Position& p)
{
	m_scene.setElem(id, p);
}

float Api::getElapsedTime()
{
	return m_event.getElapsedTime();
}







