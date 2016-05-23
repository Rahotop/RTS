#include "Enrage.hpp"

Enrage::Enrage(const Position& p, Player *pl) : Unite(70, 2, 12, 1.2, p, 9), m_player(pl), m_tmp(0)
{

}

void Enrage::boucle(const Event& e)
{
	Unite::boucle(e);
	m_tmp += e.getElapsedTime();
	
	if(m_tmp >= 1.0f)
	{
		m_player->enrageTooFar(this);
		
		m_tmp = 0.0f;
	}
}
