#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include "Cible.hpp"
#include "../Event.hpp"
#include <cmath>
#include <iostream>

class Gestionnaire;

class Element
{
	public:
	
	Element();
	Element(int vie, int portee, int degat, const Position& p, int type);
	virtual ~Element();
	
	bool isAlive() const;
	Position getPos() const;
	int getId() const;
	void setVie(int v);
	int getVie() const;
	void setDegat(int d);
	int getDegat() const;
	bool getBuff() const;
	void setBuff(bool b);
	void checkCibleAlive();
	void attaque() const;
	
	virtual void clicRightOn(const Cible& c) = 0;
	virtual void boucle(const Event& e) = 0;
	virtual int getPower();
	
	int getType();
	
	static void setGestionnaire(Gestionnaire *g);
	
	protected:
	
	Cible m_cible;
	Position m_pos;
	int m_portee;
	
	static Gestionnaire *s_gestionnaire;
	
	private:
	
	int m_id;
	int m_vie;
	int m_vieMax;
	int m_degat;
	int m_type;
	bool m_buff;
	
	static int s_id;
};

#endif






