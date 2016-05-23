#ifndef CIBLE_HPP_INCLUDED
#define CIBLE_HPP_INCLUDED

#include "Position.hpp"

class Element;

class Cible
{
	public:
	
	Cible();
	Cible(Element *e, bool a = false);
	Cible(int x, int y, bool a = false);
	Cible(const Position& p, bool a = false);
	Cible(const Cible& c);
	
	bool isCase() const;
	bool isElem() const;
	bool isActive() const;
	
	Element* getElem() const;
	Position getPos() const;
	
	Cible& operator=(const Cible& c);
	
	private:
	
	Element *m_cibleElem;
	Position m_cible;
	bool m_active;
};

#endif
