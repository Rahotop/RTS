#include "Gestionnaire.hpp"
#include "Element.hpp"
#include "Api.hpp"

Gestionnaire::Gestionnaire(Api *a) : m_elem(), m_api(a)
{
	Element::setGestionnaire(this);
}

Gestionnaire::~Gestionnaire()
{
	for(auto& x : m_elem)
	{
		delete x.second;
	}
	m_elem.clear();
}

void Gestionnaire::addElem(Element *e, int c)
{
	std::cerr << std::endl << "<addElem id=\"" << e->getId() << "\"/>" << std::endl << std::endl;
	m_elem[e->getId()] = e;
	m_api->addElem(e, c);
}

void Gestionnaire::erase(int id)
{
	std::cerr << "<erase id=\"" << id << "\">" << std::endl << std::endl;
	
	for(auto& x : m_elem)
	{
		std::cerr << "	" << x.first << "|";
	}
	
	std::cerr << std::endl;
	
	delete m_elem[id];
	m_elem.erase(id);
	m_api->eraseElem(id);
	
	std::cerr << "	" << id << " dead" << std::endl;
	
	std::cerr << std::endl << "</erase>" << std::endl << std::endl;
}

void Gestionnaire::moveElem(int id, const Position& p)
{
	m_api->setElem(id, p);
}

void Gestionnaire::boucle(const Event& e)
{
	for(auto& x : m_elem)
	{
		x.second->boucle(e);
	}
	
	for(auto& x : m_elem)
	{
		x.second->checkCibleAlive();
	}
	
	std::vector<int> hasToBeErase;
	
	for(auto& x : m_elem)
	{			
		if(!x.second->isAlive())
		{
			hasToBeErase.push_back(x.first);
		}
	}
	
	for(auto& x : hasToBeErase)
	{
		erase(x);
	}
}

float Gestionnaire::getElapsedTime()
{
	return m_api->getElapsedTime();
}

bool Gestionnaire::goOn(Element *e, const Position& p)
{
	for(auto& y : m_elem)
	{
		if(p == y.second->getPos())
		{
			e->clicRightOn(Cible(y.second, true));
								
			std::cerr << "	Element targeted with the id : " << y.first << std::endl;
			return false;
		}
	}
	return true;
}

Position Gestionnaire::step(const Position& depart, const Position& arrivee)
{
	return Position( depart.getX() + (arrivee.getX() > depart.getX()) - (arrivee.getX() < depart.getX()),
					 depart.getY() + (arrivee.getX()==depart.getX())*(arrivee.getY() > depart.getY()) - (arrivee.getX()==depart.getX())*(arrivee.getY() < depart.getY())
				   );
}




