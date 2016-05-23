#ifndef JOUEUR_HPP_INCLUDED
#define JOUEUR_HPP_INCLUDED

#include <iostream>
#include <unordered_map>
#include "Player.hpp"

class Gestionnaire;

class Joueur : public Player
{
	public:
	
	Joueur();
	
	void boucle(const Event& e);
	
	private:
	
};

#endif
