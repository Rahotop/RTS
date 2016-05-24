#include "Scene.hpp"

//Constructeur
Scene::Scene(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings settings) : sf::RenderWindow(mode, title, style, settings), m_projection(1.0), m_modelview(1.0), m_cam(0,0,300, 100,100,0), m_init(), m_map("Maps/map.txt"), m_perso()
{
	//setFramerateLimit(60); //On limite le nombre de fps
        
	Cube::init(); //On initailise la partie statique des cubes

    glEnable(GL_DEPTH_TEST); //On active le test de profondeur
    glEnable(GL_CULL_FACE); //On active le culling (anti-horaire)
    
    
	//On initilise les matrices
    m_projection = glm::perspective(70.0, (double) getSize().x / getSize().y, 1.0, 20000.0);
    m_modelview = glm::mat4(1.0);
    
    m_perso.push_back(new Personnage("Personnages/Roi.txt"));
    m_perso.push_back(new Personnage("Personnages/Paysan.txt"));
    m_perso.push_back(new Personnage("Personnages/Capitaine.txt"));
    m_perso.push_back(new Personnage("Personnages/Cavalier.txt"));
    m_perso.push_back(new Personnage("Personnages/Soigneur.txt"));
    m_perso.push_back(new Personnage("Personnages/Archer.txt"));
    m_perso.push_back(new Personnage("Personnages/Fantassin.txt"));
    m_perso.push_back(new Personnage("Personnages/Tank.txt"));
    m_perso.push_back(new Personnage("Personnages/Enrage.txt"));
}

Scene::~Scene()
{
    Cube::erase(); //On supprime la partie statique du cube
    
    for(unsigned int i(0); i < m_perso.size(); i++)
    	delete m_perso[i];
    m_perso.clear();
}

void Scene::boucle(Event *e)
{
	m_map.update(*e);
	m_cam.update(*e); //On met à jour la caméra
    
    //On clear les différents buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	//On initialise la matrice modelview pour que la caméra soit bien placée et regarde dans la bonne direction
	m_modelview = m_cam.lookAt();
	
	m_map.afficher(m_modelview, m_projection);//On affiche la map
	for(auto& x : m_perso)
	{
		x->afficher(m_modelview, m_projection);//on affiche les personnages
	}
    glUseProgram(0); //On arrête d'utiliser les shaders
    
    sf::Font cubic;
    cubic.loadFromFile("cubic.ttf");
    
	sf::Text text("gold : " + std::to_string(m_gold), cubic);
	text.setCharacterSize(20);
	
	sf::Color gold(212,175,55);
	text.setColor(gold);
		
	sf::CircleShape shape(50);
	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));
	
	 // Draw text on top of the 3D object
	pushGLStates();
	draw(text);
	popGLStates();
	
    display(); // On affiche
}

void Scene::changeViewPort(int x, int y)
{
	glViewport(0, 0, x, y);
    m_projection = glm::perspective(70.0, (double) x / y, 1.0, 20000.0);
}

Camera Scene::getCam()
{
	return m_cam;
}

void Scene::addElem(int id, const Position& p, int c)
{
	m_perso[c]->setElem(id, p);
}

void Scene::setElem(int id, const Position& p)
{
	for(auto& x : m_perso)
	{
		if(x->count(id) > 0)
		{
			x->setElem(id, p);
		}
	}
}

int Scene::getGold()
{
	return m_gold;
}

void Scene::setGold(int g)
{
	m_gold = g;
}

void Scene::eraseElem(int id)
{
	for(auto& x : m_perso)
	{
		x->eraseElem(id);
	}
}






