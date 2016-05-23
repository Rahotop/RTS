#include "Cible.hpp"
#include "Element.hpp"


Cible::Cible() : m_cibleElem(nullptr), m_cible(0,0), m_active(false)
{
	
}

Cible::Cible(Element *e, bool a) : m_cibleElem(e), m_cible(0,0), m_active(a)
{
	
}

Cible::Cible(int x, int y, bool a) : m_cibleElem(nullptr), m_cible(x,y), m_active(a)
{
	
}

Cible::Cible(const Position& p, bool a) : m_cibleElem(nullptr), m_cible(p), m_active(a)
{
	
}

Cible::Cible(const Cible& c) : m_cibleElem(c.m_cibleElem), m_cible(c.m_cible), m_active(c.m_active)
{
	
}

bool Cible::isCase() const
{
	return m_cibleElem == nullptr;
}

bool Cible::isElem() const
{
	return m_cibleElem != nullptr;
}

bool Cible::isActive() const
{
	return m_active;
}

Element* Cible::getElem() const
{
	return m_cibleElem;
}

Position Cible::getPos() const
{
	return m_cible;
}

Cible& Cible::operator=(const Cible& c)
{
	m_cibleElem = c.m_cibleElem;
	m_cible = c.m_cible;
	
	return *this;
}

