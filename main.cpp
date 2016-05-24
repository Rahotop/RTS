#define GLM_FORCE_RADIANS
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Moteur_RTS/Api.hpp"
#include "Init.hpp"

int main()
{
	//Contexte OpenGL dans une fenetre SFML
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 4;
	settings.minorVersion = 4;
	
	//Affichage des paramètres
	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
	
	//Ouverture de la fenetre
	Api a(settings);
	
	//Boucle de rendu
	a.boucle();
	
	return 0;
}
