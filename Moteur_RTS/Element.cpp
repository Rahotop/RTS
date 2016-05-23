#include "Element.hpp"
#include "Gestionnaire.hpp"

int Element::s_id = 0;
Gestionnaire *Element::s_gestionnaire = nullptr;

Element::Element() : m_cible(), m_pos(), m_portee(0), m_id(s_id++), m_vie(0), m_vieMax(0), m_degat(0), m_type(0), m_buff(false)
{
	std::cout << "Constructeur par défaut element " << m_id << std::endl;
}

Element::Element(int vie, int portee, int degat, const Position& p, int type) : m_cible(p), m_pos(p),m_portee(portee), m_id(s_id++), m_vie(vie), m_vieMax(vie), m_degat(degat), m_type(type), m_buff(false)
{
	std::cout << "Constructeur element " << m_id << std::endl;
}

Element::~Element()
{
	
}

bool Element::isAlive() const
{
	return m_vie > 0;
}

Position Element::getPos() const
{
	return m_pos;
}

int Element::getId() const
{
	return m_id;
}

void Element::setVie(int v)
{
	m_vie = v;
}

int Element::getVie() const
{
	return m_vie;
}

void Element::setDegat(int d)
{
	m_degat = d;
}

int Element::getDegat() const
{
	return m_degat;
}

void Element::checkCibleAlive()
{
	if(m_cible.isElem())
	{
		if(!m_cible.getElem()->isAlive())
		{
			m_cible = Cible(m_pos);
			std::cerr << m_pos.getX() << ";" << m_pos.getY() << std::endl;
		}
	}
}

void Element::attaque() const
{
	if(m_buff)
	{
		m_cible.getElem()->m_vie -= m_degat + 3;
	}
	else
	{
		m_cible.getElem()->m_vie -= m_degat;
	}
	if(m_cible.getElem()->m_vie > m_cible.getElem()->m_vieMax)
	{
		m_cible.getElem()->m_vie = m_cible.getElem()->m_vieMax;
	}
	std::cout << "vie restante : " << m_cible.getElem()->m_vie << std::endl;
}



bool Element::getBuff() const
{
	return m_buff;
}

void Element::setBuff(bool b)
{
	m_buff = b;
}

void Element::setGestionnaire(Gestionnaire *g)
{
	s_gestionnaire = g;
}

int Element::getPower()
{
	return (m_portee*m_degat)+((m_degat*m_degat)/2)+m_vie;
}

int Element::getType()
{
	return m_type;
}

