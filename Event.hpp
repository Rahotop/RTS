#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include <SFML/Window.hpp>

class Scene;

enum Touche
{
	ECHAP,
	ClickG,
	ClickD,
	END
};

class Event : public sf::Event
{
	public:
	
	Event(Scene *w);
	
	void update();
	bool isRunning();
	void stop();
	
	private:
	
	Scene *m_win;
	bool m_running;
};

#endif
