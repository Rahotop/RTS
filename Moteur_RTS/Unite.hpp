#ifndef UNITE_HPP_INCLUDED
#define UNITE_HPP_INLCUDED

#include "Element.hpp"
#include <cstdlib>

class Unite : public Element
{
	public:
	
	Unite();
	Unite(int vie, int portee, int degat, float vitesse, const Position& p, int type);
	
	void clicRightOn(const Cible& c);	
	bool rangeOk() const;
	virtual void boucle(const Event& e);
	int getPower();
	
	private:
	
	float m_vitesse;
	Cible m_cibleTmp;
	float m_tmpPos;
	float m_tmpAttaque;
};

#endif
