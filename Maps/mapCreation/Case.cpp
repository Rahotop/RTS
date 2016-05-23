#include "Case.hpp"

Case::Case() : m_biome(nullptr), m_couleur(0,0,0), m_hauteur(1)
{

}

Biome * Case::getBiome()
{
	return m_biome;
}

unsigned int Case::getHauteur()
{
	return m_hauteur;
}

bool Case::getBool()
{
	return m_bool;
}

Couleur Case::getCouleur()
{
    return m_couleur;
}

void Case::setBool(bool b)
{
	m_bool = b;
}

void Case::setBiome(Biome *biome)
{
	m_biome = biome;
	m_couleur = m_biome->getRandCouleur();
}

void Case::setCouleur()
{
    m_couleur = m_biome->getRandCouleur();
}

void Case::setHauteur(unsigned int h)
{
    m_hauteur = h;
}
