#ifndef GESTIONNAIRE_HPP_INCLUDED
#define GESTIONNAIRE_HPP_INCLUDED

#include <vector>
#include <unordered_map>
#include "Position.hpp"
#include "../Event.hpp"

class Element;
class Api;

class Gestionnaire
{
	public:
	
	Gestionnaire(Api *a);
	~Gestionnaire();
	
	void addElem(Element *e, int c);
	void erase(int id);
	
	void moveElem(int id, const Position& p);
	
	void boucle(const Event& e);
	
	float getElapsedTime();
	
	bool goOn(Element *e, const Position& p);
	
	Position step(const Position& depart, const Position& arrivee);
	
	private:
	
	std::unordered_map<int, Element*> m_elem;
	
	Api *m_api;
};

#endif
