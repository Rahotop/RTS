#include "Joueur.hpp"
#include "Gestionnaire.hpp"
#include "Element.hpp"
#include "Paysan.hpp"
#include "Capitaine.hpp"
#include "Cavalier.hpp"
#include "Soigneur.hpp"
#include "Archer.hpp"
#include "Fantassin.hpp"
#include "Tank.hpp"
#include "Enrage.hpp"

Joueur::Joueur() : Player()
{
	
}

void Joueur::boucle(const Event& e)
{	
	if((e.getTouche()[Touche::ENTER]) && (e.getTouche()[Touche::ZERO]))
	{
		bool create(true);
		
		std::cerr << "<select>" << std::endl << std::endl;
		
		for(auto& x : m_elem)
		{
			if(e.getSelect() == x.second->getPos())
			{
				create = false;
				
				std::cerr << "	Element selected with the id : " << x.first << std::endl;
				
				if(s_gestionnaire->goOn(x.second, e.getCible()))
				{
					std::cerr << "	Element selected goes to (" << e.getCible().getX() << ";" << e.getCible().getY() << ")" << std::endl;
					x.second->clicRightOn(Cible(e.getCible(), true));
				}
			}
		}
		
		if(create)
		{
			Element *elem(nullptr);
		
			switch(e.getNum())
			{
				case 0 : 
					if (getGold()>=5000)
					{
						elem = new Roi(e.getCible(),this);
						removeGold(5000);
					}
					break;
				case 1 :
					if (getGold()>=800)
					{
						if (createPaysan(e))
						{
							elem = new Paysan(e.getCible());
							removeGold(800);
						}
						else if (createEnrage(e))
						{
							elem = new Enrage(e.getCible(),this);
							removeGold(800);
						}
					}
					break;
				case 2 :
					if (getGold()>=1800)
					{
						if (createCapitaine(e))
						{
							elem = new Capitaine(e.getCible());
							removeGold(1800);
						}
					}
					break;
				case 3 :
					if (getGold()>=1200 && createUnitByCap(e))
					{
						elem = new Cavalier(e.getCible());
						removeGold(1200);
					}
					break;
				case 4 :
					if (getGold()>=2000 && createUnitByCap(e))
					{
						elem = new Soigneur(e.getCible());
						removeGold(2000);
					}
					break;
				case 5 :
					if (getGold()>=1000 && createUnitByCap(e))
					{
						elem = new Archer(e.getCible());
						removeGold(1000);
					}
					break;
				case 6 :
					if (getGold()>=1200 && createUnitByCap(e))
					{
						elem = new Fantassin(e.getCible());
						removeGold(1200);
					}
					break;
				case 7 :
					if (getGold()>=1200 && createUnitByCap(e))
					{
						elem = new Tank(e.getCible());
						removeGold(1200);
					}
					break;
			}
			
			if(elem != nullptr)
			{
				s_gestionnaire->addElem(elem, elem->getType()-1);
				m_elem[elem->getId()] = elem;
				std::cerr << "	Element created with the id : " << elem->getId() << std::endl;
			}
		}
		
		
		e.getTouche()[Touche::ENTER] = false;
		e.getTouche()[Touche::ZERO] = false;
		
		std::cerr << std::endl << "</select>" << std::endl << std::endl;
	}
	
	
}



