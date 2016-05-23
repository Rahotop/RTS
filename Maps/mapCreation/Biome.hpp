#ifndef BIOME_HPP_INCLUDED
#define BIOME_HPP_INCLUDED

#include "Couleur.hpp"
#include <vector>
#include <cstdlib>

class Biome
{
	public:

    Biome();

    void addCouleur(int r, int v, int b);
    void setHauteurMax(unsigned int h);
    void setHauteurMin(unsigned int h);
    void setFacteur(unsigned int h);
    void setPoids(unsigned int h);
    void setObstacle(unsigned int o);
    Couleur getRandCouleur();
    unsigned int getHauteurMax();
    unsigned int getHauteurMin();
    unsigned int getFacteur();
    unsigned int getPoids();
    unsigned int getObstacle();

	private:

    std::vector<Couleur> m_tabCouleurs;
    unsigned int m_hauteurMax;
    unsigned int m_hauteurMin;
    unsigned int m_facteur;
    unsigned int m_poids;
	unsigned int m_obstacle;
};

#endif
