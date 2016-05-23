#include "Roi.hpp"

Roi::Roi(const Position& p, Player *pl) : Unite(100, 1, 8, 0.8, p, 1), m_player(pl), m_tmp(0)
{

}

void Roi::boucle(const Event& e)
{
	Unite::boucle(e);
	m_tmp += e.getElapsedTime();
	
	if(m_tmp >= 1.0f)
	{
		m_player->capitaineUnite();
		m_player->addGold(10);
		m_player->addGold(m_player->paysanRoi(this)*2);
		m_player->addGold(m_player->enrageRoi(this));
		
		m_tmp = 0.0f;
	}
}
