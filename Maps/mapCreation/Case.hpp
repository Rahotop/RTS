#ifndef CASE_HPP_INCLUDED
#define CASE_HPP_INCLUDED

#include "Biome.hpp"
#include "Couleur.hpp"

class Case
{
	public:

	Case();

	Biome * getBiome();
	unsigned int getHauteur();
	bool getBool();
	Couleur getCouleur();

	void setBool(bool b);
	void setBiome(Biome *biome);
	void setCouleur();
	void setHauteur(unsigned int h);

	private:


	bool m_bool;
	Biome *m_biome;
	Couleur m_couleur;
	unsigned int m_hauteur;
};

#endif
