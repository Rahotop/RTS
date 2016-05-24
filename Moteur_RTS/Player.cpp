#include "Player.hpp"
#include "Element.hpp"
#include "Roi.hpp"
#include "Gestionnaire.hpp"

Gestionnaire *Player::s_gestionnaire = nullptr;

Player::Player() : m_elem(), m_gold(100000)
{
	
}

void Player::initPlayer(const Position& p)
{
	Element * elem = new Roi(p,this);
	s_gestionnaire->addElem(elem, 0);
	m_elem[elem->getId()] = elem;
}

void Player::addElem(Element *e)
{
	m_elem[e->getId()] = e;
}

void Player::eraseElem(int id)
{
	m_elem.erase(id);
}

int Player::update()
{
	int tmp(0);
	for(auto& x: m_elem)
	{
		tmp += x.second->getPower();
	}
	
	return tmp + m_gold/4;
}

void Player::addGold(unsigned int x)
{
	m_gold += x;
}

void Player::removeGold(unsigned int x)
{
	m_gold -= x;
}

int Player::getGold()
{
	return m_gold;
}

void Player::setGestionnaire(Gestionnaire *g)
{
	s_gestionnaire = g;
}

void Player::capitaineUnite()
{
	for(auto & x : m_elem)
	{
		if(x.second->getType() == 3)
		{
			for(auto & y : m_elem)
			{
				if((abs(x.second->getPos().getX() - y.second->getPos().getX()) <= 3) && (abs(x.second->getPos().getY() - y.second->getPos().getY()) <= 3))
				{
					y.second->setBuff(true);
				}
				
			}
		}
	}
}

int Player::paysanRoi(Element* e)
{
	int nbPaysan(0);
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 2)
		{
			if((abs(e->getPos().getX() - x.second->getPos().getX()) == 5 && abs(e->getPos().getY() - x.second->getPos().getY()) <= 5) || (abs(e->getPos().getX() - x.second->getPos().getX()) <= 5 && abs(e->getPos().getY() - x.second->getPos().getY()) == 5))
			{
				nbPaysan++;
			}
		}
	}
	return nbPaysan;
}

void Player::enrageTooFar(Element* e)
{
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 1)
		{
			if((abs(x.second->getPos().getX() - e->getPos().getX()) > 4) || (abs(x.second->getPos().getY() - e->getPos().getY()) > 4))
			{
				e->setVie(e->getVie() - e->getDegat());
				std::cout << "vie : " << e->getVie() << std::endl;
			}
		}
	}
}

int Player::enrageRoi(Element* e)
{
	int nbEnrage(0);
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 9)
		{
			if((abs(x.second->getPos().getX() - e->getPos().getX()) <= 4) && (abs(x.second->getPos().getY() - e->getPos().getY()) <= 4))
			{
				nbEnrage++;
			}
		}
	}
	return nbEnrage;
}

bool Player::createPaysan(const Event& e)
{
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 1)
		{
			if((abs(e.getCible().getX() - x.second->getPos().getX()) == 5 && abs(e.getCible().getY() - x.second->getPos().getY()) <= 5) || (abs(e.getCible().getX() - x.second->getPos().getX()) <= 5 && abs(e.getCible().getY() - x.second->getPos().getY()) == 5))
			{
				return true;
			}
		}
	}
	return false;
}

bool Player::createEnrage(const Event& e)
{
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 1)
		{
			if((abs(e.getCible().getX() - x.second->getPos().getX()) <= 4) && (abs(e.getCible().getY() - x.second->getPos().getY()) <= 4))
			{
				return true;
			}
		}
	}
	return false;
}

bool Player::createCapitaine(const Event& e)
{
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 1)
		{
			if((abs(e.getCible().getX() - x.second->getPos().getX()) <= 5) && (abs(e.getCible().getY() - x.second->getPos().getY()) <= 5))
			{
				return true;
			}
		}
	}
	return false;
}

bool Player::createUnitByCap(const Event& e)
{
	for(auto& x : m_elem)
	{
		if(x.second->getType() == 3)
		{
			if((abs(e.getCible().getX() - x.second->getPos().getX()) <= 10) && (abs(e.getCible().getY() - x.second->getPos().getY()) <= 10))
			{
				return true;
			}
		}
	}
	return false;
}
