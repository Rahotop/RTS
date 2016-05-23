#ifndef ENRAGE_HPP_INCLUDED
#define ENRAGE_HPP_INCLUDED

#include "Roi.hpp"

class Enrage : public Unite
{

	public :
	
	Enrage(const Position& p, Player *pl);
	void boucle(const Event& e);
	
	private :
	
	Player * m_player;
	float m_tmp;

};

#endif
