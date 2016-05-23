#include "Biome.hpp"

Biome::Biome() : m_tabCouleurs()
{

}

void Biome::addCouleur(int r, int v, int b)
{
    Couleur c(r,v,b);
    m_tabCouleurs.push_back(c);
}

void Biome::setHauteurMax(unsigned int h)
{
    m_hauteurMax = h;
}

void Biome::setHauteurMin(unsigned int h)
{
    m_hauteurMin = h;
}

void Biome::setFacteur(unsigned int h)
{
    m_facteur = h;
}

void Biome::setPoids(unsigned int h)
{
    m_poids = h;
}

void Biome::setObstacle(unsigned int o)
{
	m_obstacle = o;
}

Couleur Biome::getRandCouleur()
{
    int indTmp = rand()%(m_tabCouleurs.size());
    return m_tabCouleurs[indTmp];
}

unsigned int Biome::getHauteurMax()
{
    return m_hauteurMax;
}

unsigned int Biome::getHauteurMin()
{
    return m_hauteurMin;
}

unsigned int Biome::getFacteur()
{
    return m_facteur;
}

unsigned int Biome::getPoids()
{
    return m_poids;
}

unsigned int Biome::getObstacle()
{
	return m_obstacle;
}
