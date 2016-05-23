#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "Case.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

class Map
{

	public:

	Map();
	Map(int taille,std::string path);
	~Map();

	void initMap();
	void propagation();
	void remplissage();
	void save(std::string path, std::string path1);


	private:

	unsigned int m_taille;
	unsigned int m_nbBiomes;
	Case **m_tabCases;
	Biome *m_tabBiomes;
	unsigned int m_poidsMax;
};

#endif
