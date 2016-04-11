#include "Event.hpp"
#include "Scene.hpp"

Event::Event(Scene *w) : sf::Event(), m_win(w), m_running(true)
{
	
}

void Event::update()
{
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
    }
}

bool Event::isRunning()
{
	return m_running;
}

void Event::stop()
{
	m_running = false;
}

