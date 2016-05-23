#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <unordered_map>
#include "../Event.hpp"

class Gestionnaire;
class Element;

class Player
{
	public:
	
	Player();
	
	void initPlayer(const Position& p);
	
	void addElem(Element *e);
	void eraseElem(int id);
	
	int update();
	virtual void boucle(const Event& e) = 0;
	
	void addGold(unsigned int x);
	void removeGold(unsigned int x);
	int getGold();
	int paysanRoi(Element* e);
	int enrageRoi(Element* e);
	void enrageTooFar(Element* e);
	void capitaineUnite();
	bool createPaysan(const Event& e);
	bool createEnrage(const Event& e);
	bool createUnitByCap(const Event& e);
	
	static void setGestionnaire(Gestionnaire *g);
	
	protected:
	
	static Gestionnaire *s_gestionnaire;
	std::unordered_map<int, Element*> m_elem;
	
	private:
	
	int m_gold;
};

#endif
