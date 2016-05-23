#ifndef ROI_HPP_INCLUDED
#define ROI_HPP_INCLUDED

#include "Unite.hpp"
#include "Player.hpp"

class Roi : public Unite
{

	public :
	
	Roi(const Position& p, Player *pl);
	
	void boucle(const Event& e);
	
	private :
	
	Player * m_player;
	float m_tmp;

};

#endif
