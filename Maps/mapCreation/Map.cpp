#include "Map.hpp"

Map::Map() :  m_taille(0), m_tabCases(nullptr)
{

}

Map::Map(int taille, std::string path) :  m_taille(taille), m_nbBiomes(0), m_tabCases(new Case*[taille]), m_poidsMax(0)
{
    for (int i(0); i<taille; i++)
    {
        m_tabCases[i]=new Case[taille];
    }

    std::ifstream in(path.c_str());
    in >> m_nbBiomes;
    m_tabBiomes = new Biome[m_nbBiomes];
    for (unsigned int i(0); i<m_nbBiomes; i++)
    {
        int nbCouleurs;
        unsigned int hauteurMax;
        unsigned int hauteurMin;
        unsigned int facteur;
        unsigned int poids;
        unsigned int obstacle;
        in >> nbCouleurs >> hauteurMax >> hauteurMin >> facteur >> poids >> obstacle;
        m_poidsMax += poids;
        for (int j(0); j<nbCouleurs; j++)
        {
            int r,v,b;
            in >> r >> v >> b;
            m_tabBiomes[i].addCouleur(r,v,b);
            m_tabBiomes[i].setHauteurMax(hauteurMax);
            m_tabBiomes[i].setHauteurMin(hauteurMin);
            m_tabBiomes[i].setFacteur(facteur);
            m_tabBiomes[i].setPoids(poids);
            m_tabBiomes[i].setObstacle(obstacle);
        }
    }

	for(int j(0); j<taille; j++)
		for(int i(0); i<taille; i++)
			m_tabCases[i][j].setBool(true); //vrai si on peut propager le biome

}

Map::~Map()
{
	delete[] m_tabCases;
}

void Map::initMap()
{
	//on place les points qui vont se propager sur une position random de la map avec un biome random du tableau des biomes
	for(unsigned int i(0); i<(m_taille/8); i++)
	{
	    int randBiome(rand()%m_poidsMax);
	    int tmp(0);
	    for(int i(0); i < m_nbBiomes; i++)
	    {
	    	tmp += m_tabBiomes[i].getPoids();
	    	if(tmp > randBiome)
	    	{
	    		randBiome = i;
	    		break;
	    	}
	    }	    
	    
	    int randCasei = rand()%m_taille;
	    int randCasej = rand()%m_taille;
	    std::cout << randBiome << " " << randCasei << " " << randCasej << std::endl;
		m_tabCases[randCasei][randCasej].setBiome(&(m_tabBiomes[randBiome]));
		m_tabCases[randCasei][randCasej].setHauteur(m_tabBiomes[randBiome].getHauteurMax());
	}
}

void Map::propagation()
{
	//1 tour de propagation
	for(unsigned int j(0); j<m_taille; j++)
		for(unsigned int i(0); i<m_taille; i++)
		{
		    if(m_tabCases[i][j].getBool() && m_tabCases[i][j].getBiome()!=nullptr)
            {
                if(j+1 < m_taille)
                {
                    if((m_tabCases[i][j+1].getBiome()==nullptr))
                    {
                        m_tabCases[i][j+1].setBiome(m_tabCases[i][j].getBiome());
                        m_tabCases[i][j+1].setBool(false);
                        
                        //Hauteur
                        if(m_tabCases[i][j].getHauteur() > m_tabCases[i][j].getBiome()->getHauteurMin())
                        	m_tabCases[i][j+1].setHauteur(m_tabCases[i][j].getHauteur()-m_tabCases[i][j].getBiome()->getFacteur());
                        else
                        	m_tabCases[i][j+1].setHauteur(m_tabCases[i][j].getBiome()->getHauteurMin());
                    }
                }
                if(j > 0)
                {
                    if((m_tabCases[i][j-1].getBiome()==nullptr))
                    {
                        m_tabCases[i][j-1].setBiome(m_tabCases[i][j].getBiome());
                        m_tabCases[i][j-1].setBool(false);
                        
                        //Hauteur
                        if(m_tabCases[i][j].getHauteur() > m_tabCases[i][j].getBiome()->getHauteurMin())
                        	m_tabCases[i][j-1].setHauteur(m_tabCases[i][j].getHauteur()-m_tabCases[i][j].getBiome()->getFacteur());
                        else
                        	m_tabCases[i][j-1].setHauteur(m_tabCases[i][j].getBiome()->getHauteurMin());
                    }
                }
                if(i+1 < m_taille)
                {
                    if((m_tabCases[i+1][j].getBiome()==nullptr))
                    {
                        m_tabCases[i+1][j].setBiome(m_tabCases[i][j].getBiome());
                        m_tabCases[i+1][j].setBool(false);
                        
                        //Hauteur
                        if(m_tabCases[i][j].getHauteur() > m_tabCases[i][j].getBiome()->getHauteurMin())
                        	m_tabCases[i+1][j].setHauteur(m_tabCases[i][j].getHauteur()-m_tabCases[i][j].getBiome()->getFacteur());
                        else
                        	m_tabCases[i+1][j].setHauteur(m_tabCases[i][j].getBiome()->getHauteurMin());
                    }
                }
                if(i > 0)
                {
                    if((m_tabCases[i-1][j].getBiome()==nullptr))
                    {
                        m_tabCases[i-1][j].setBiome(m_tabCases[i][j].getBiome());
                        m_tabCases[i-1][j].setBool(false);
                        
                        //Hauteur
                        if(m_tabCases[i][j].getHauteur() > m_tabCases[i][j].getBiome()->getHauteurMin())
                        	m_tabCases[i-1][j].setHauteur(m_tabCases[i][j].getHauteur()-m_tabCases[i][j].getBiome()->getFacteur());
                        else
                        	m_tabCases[i-1][j].setHauteur(m_tabCases[i][j].getBiome()->getHauteurMin());
                    }
                }
            }
		}
}

void Map::remplissage()
{
	bool tmp = true;
	while(tmp)
	{
		propagation();
		tmp=false;
		for(unsigned int j(0); j<m_taille; j++)
			for(unsigned int i(0); i<m_taille; i++)
			{
				m_tabCases[i][j].setBool(true);
				if (m_tabCases[i][j].getBiome()==nullptr)
				{
					tmp=true;
				}
			}
	}
}

void Map::save(std::string path, std::string path1)
{
    std::ofstream out(path.c_str(), std::ios::out | std::ios::trunc);
    
    std::ofstream out1(path1.c_str(), std::ios::out | std::ios::trunc);
    
    for(unsigned int j(0); j<m_taille; j++)
        for(unsigned int i(0); i<m_taille; i++)
        {
        	if(m_tabCases[i][j].getBiome()->getObstacle() == 1)
        	{
			    out1 << i << " ";
			    out1 << j << " pouet  ";
			    out1 << m_tabCases[i][j].getBiome()->getObstacle() << std::endl;
	        }
        }
    
    if(out.is_open())
    	std::cout << "ouverture du fichier réussi" << std::endl;
    
    out << m_taille << " " << m_taille << std::endl;
    for(unsigned int j(0); j<m_taille; j++)
        for(unsigned int i(0); i<m_taille; i++)
        {
	        out << m_tabCases[i][j].getCouleur().getR() << " ";
	        out << m_tabCases[i][j].getCouleur().getV() << " ";
	        out << m_tabCases[i][j].getCouleur().getB() << " ";
	        out << m_tabCases[i][j].getHauteur() << std::endl;
        }
}








