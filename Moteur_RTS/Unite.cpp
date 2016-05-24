#include "Unite.hpp"
#include "Gestionnaire.hpp"

Unite::Unite() : Element(), m_vitesse(0.0f), m_cibleTmp(), m_tmpPos(0.0f), m_tmpAttaque(0.0f)
{
	
}

Unite::Unite(int vie, int portee, int degat, float vitesse, const Position& p, int type) : Element(vie, portee, degat, p, type), m_vitesse(vitesse), m_cibleTmp(p), m_tmpPos(0.0f), m_tmpAttaque(0.0f)
{
	
}

void Unite::clicRightOn(const Cible& c)
{
	m_cible = c;
	m_cibleTmp = Cible(s_gestionnaire->step(m_pos, m_cible.getPos()));;
	if(c.isElem() && c.getPos() == m_pos)
	{
		m_cible = Cible(m_pos);
		m_cibleTmp = Cible(m_pos);
	}
	else if(c.isElem())
	{
		m_cibleTmp = Cible(s_gestionnaire->step(m_pos, m_cible.getElem()->getPos()));
	}
}

bool Unite::rangeOk() const
{
	if (abs(m_cible.getElem()->getPos().getX() - m_pos.getX()) <= m_portee && abs(m_cible.getElem()->getPos().getY() - m_pos.getY()) <= m_portee)
		{
			return true;
		}
	else {return false;}
}


void Unite::boucle(const Event& e)
{
	if(m_cible.isElem())
	{
		if(rangeOk())
		{	
			s_gestionnaire->moveElem(getId(), m_pos+((m_cible.getElem()->getPos()-m_pos)*0.1f*m_tmpAttaque));
		}
		
		if(rangeOk() && m_tmpAttaque <= 0)
		{
			attaque();
			m_tmpAttaque=1.0f;
		}
		else if(!rangeOk())
		{
			m_tmpPos += m_vitesse*s_gestionnaire->getElapsedTime();
			
			if(m_tmpPos >= 1.0f)
			{
				m_pos = m_cibleTmp.getPos();
				
				m_cibleTmp = Cible(s_gestionnaire->step(m_pos, m_cible.getElem()->getPos()));
				m_tmpPos = 0.0f;
			}
			
			s_gestionnaire->moveElem(getId(), m_pos+((m_cibleTmp.getPos()-m_pos)*m_tmpPos));
		}
	}
	else
	{
		m_tmpPos += m_vitesse*s_gestionnaire->getElapsedTime();
		
			
		if(m_tmpPos >= 1.0f)
		{
			m_pos = m_cibleTmp.getPos();
			
			m_cibleTmp = Cible(s_gestionnaire->step(m_pos, m_cible.getPos()));
			m_tmpPos = 0.0f;
		}
		
		s_gestionnaire->moveElem(getId(), m_pos+((m_cibleTmp.getPos()-m_pos)*m_tmpPos));
	}
	
	m_tmpAttaque -= s_gestionnaire->getElapsedTime();
	
	if(m_tmpAttaque <= 0.0f)
	{
		m_tmpAttaque = 0.0f;
	}
}

int Unite::getPower()
{
	return Element::getPower() + getVie()*((m_vitesse+1)/2);
}



