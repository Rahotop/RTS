#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Position.hpp"

//Déclaration de la classe Scene
class Scene;

//Enumeration des touches utiles pour l'execution du programme
enum Touche
{
	ECHAP,
	ClickL,
	ClickR,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ENTER,
	ZERO,
	UN,
	DEUX,
	TROIS,
	QUATRE,
	CINQ,
	SIX,
	SEPT,
	HUIT,
	SEC,
	END
};

//Classe qui gère les évennements
class Event : public sf::Event
{
	public:
	
	//Constructeur qui prend en paramètre une scene hérite de la classe SFML sf::Window
	Event(Scene *w);
	
	~Event();
	
	//Methode de mise à jour des events
	void update();
	//Methode qui retourne l'état de la fenetre
	bool isRunning();
	//Stoppe la fenetre
	void stop();
	
	Scene *getWin();
	int getDeltaWheel();	
	bool *getTouche() const;
	
	void setDeltaWheel(int s);
	
	int getMouseX() const;
	int getMouseY() const;
	
	Position getSelect() const;
	Position getCible() const;
	Position getCursor() const;
	
	int getNum() const;
	
	void setSelect(const Position& s);
	void setCible(const Position& c);
	void setCursor(const Position& c);
	
	void setNum(int n);
	
	float getElapsedTime() const; 
	
	private:
	
	Scene *m_win;
	bool m_running;
	bool *m_touche;
	
    sf::Clock m_clock;
    int m_fps;
    float m_elapsed;
    float m_precT;
    
    //molette
    int m_deltaWheel;
    
    int m_mouseX;
    int m_mouseY;
    
    Position m_selec;
    Position m_cible;
    Position m_cursor;
    
    int m_num;
};

#endif
