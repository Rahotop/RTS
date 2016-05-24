#include "Event.hpp"
#include "Scene.hpp"

//Constructeur qui prend un scene en parametre
Event::Event(Scene *w) : sf::Event(), m_win(w), m_running(true), m_touche(new bool[Touche::END]), m_clock(), m_fps(0), m_elapsed(0.0f), m_precT(0.0f), m_deltaWheel(0), m_mouseX(0), m_mouseY(0), m_selec(), m_cible(), m_num(1)
{
	for(int i(0); i < Touche::END; i++)
	{
		m_touche[i] = false;
	}
}

Event::~Event()
{
	delete[] m_touche;
}

//Mise à jour des events
void Event::update()
{
	//Gestion des events
	
	while(m_win->pollEvent(*this))
    {
        if(this->type == sf::Event::Closed)
        {
            m_running = false;
        }
        else if(this->type == sf::Event::Resized)
        {
            m_win->changeViewPort(this->size.width, this->size.height);
        }
    	else if (this->type == sf::Event::MouseButtonPressed)
		{
			if (this->mouseButton.button == sf::Mouse::Left)
			{
				m_touche[Touche::ClickL] = true;
			}
			else if (this->mouseButton.button == sf::Mouse::Right)
			{
				 m_touche[Touche::ClickR] = true;
					 
			}
		}
		else if (this->type == sf::Event::MouseWheelMoved)
		{
			m_deltaWheel = this->mouseWheel.delta;
		}
		else if (this->type == sf::Event::MouseMoved)
		{
			m_mouseX = this->mouseMove.x;
			m_mouseY = this->mouseMove.y;
		}
		else if (this->type == sf::Event::KeyPressed)
		{
			if (this->key.code == sf::Keyboard::Up)
			{
				m_touche[Touche::UP] = true;
			}
			else if (this->key.code == sf::Keyboard::Down)
			{
				m_touche[Touche::DOWN] = true;
			}
			else if (this->key.code == sf::Keyboard::Left)
			{
				m_touche[Touche::LEFT] = true;
			}
			else if (this->key.code == sf::Keyboard::Right)
			{
				m_touche[Touche::RIGHT] = true;
			}
			else if (this->key.code == sf::Keyboard::Return)
			{
				m_touche[Touche::ENTER] = true;
				m_selec = m_cursor;
			}
			else if (this->key.code == sf::Keyboard::Numpad0)
			{
				m_touche[Touche::ZERO] = true;
				m_cible = m_cursor;
			}
			else if (this->key.code == sf::Keyboard::Numpad1)
			{
				m_touche[Touche::UN] = true;
				m_num = 0;
			}
			else if (this->key.code == sf::Keyboard::Numpad2)
			{
				m_touche[Touche::DEUX] = true;
				m_num = 1;
			}
			else if (this->key.code == sf::Keyboard::Numpad3)
			{
				m_touche[Touche::TROIS] = true;
				m_num = 2;
			}
			else if (this->key.code == sf::Keyboard::Numpad4)
			{
				m_touche[Touche::QUATRE] = true;
				m_num = 3;
			}
			else if (this->key.code == sf::Keyboard::Numpad5)
			{
				m_touche[Touche::CINQ] = true;
				m_num = 4;
			}
			else if (this->key.code == sf::Keyboard::Numpad6)
			{
				m_touche[Touche::SIX] = true;
				m_num = 5;
			}
			else if (this->key.code == sf::Keyboard::Numpad7)
			{
				m_touche[Touche::SEPT] = true;
				m_num = 6;
			}
			else if (this->key.code == sf::Keyboard::Numpad8)
			{
				m_touche[Touche::HUIT] = true;
				m_num = 7;
			}
		}
    }
    
    //Gestion des cas spéciaux
    
    if(!m_touche[Touche::ENTER] && m_touche[Touche::ZERO])
    {
    	m_touche[Touche::ZERO] = false;
    }
    
    //Gestion du temps
    
    float tmpE(m_clock.getElapsedTime().asSeconds());
    if(tmpE < m_precT)
    {
    	m_elapsed = (1+tmpE) - m_precT;
    }
    else
    {
		m_elapsed = tmpE - m_precT;
    }
	m_precT = tmpE;
    
    //Comptage et affichage des fps
    
    if(m_clock.getElapsedTime().asSeconds() >= 1.0f)
    {
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
        	std::cout << "fps : " << m_fps+1 << std::endl;
        m_clock.restart();
        m_fps = 0;
        m_touche[Touche::SEC] = true;
    }
    else
    {
        m_fps++;        
        m_touche[Touche::SEC] = false;
    }
}

//Retourne l'état de la fenetre
bool Event::isRunning()
{
	return m_running;
}

//Stoppe la fenetre
void Event::stop()
{
	m_running = false;
}

Scene * Event::getWin()
{
	return m_win;
}

int Event::getDeltaWheel()
{
	return m_deltaWheel;
}

bool * Event::getTouche() const
{
	return m_touche;
}

void Event::setDeltaWheel(int s)
{
	m_deltaWheel = s;
}

int Event::getMouseX() const
{
	return m_mouseX;
}

int Event::getMouseY() const
{
	return m_mouseY;
}	

Position Event::getSelect() const
{
	return m_selec;
}

Position Event::getCible() const
{
	return m_cible;
}

Position Event::getCursor() const
{
	return m_cursor;
}

int Event::getNum() const
{
	return m_num;
}

void Event::setSelect(const Position& s)
{
	m_selec = s;
}

void Event::setCible(const Position& c)
{
	m_cible = c;
}


void Event::setCursor(const Position& c)
{
	m_cursor = c;
}

void Event::setNum(int n)
{
	m_num = n;
}

float Event::getElapsedTime() const
{
	return m_elapsed;
}













