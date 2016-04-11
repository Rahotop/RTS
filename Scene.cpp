#include "Scene.hpp"

Scene::Scene(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings settings) : sf::Window(mode, title, style, settings), m_projection(1.0), m_modelview(1.0), m_event(this)
{
	setFramerateLimit(60);
	glewInit();
	Cube::init();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

Scene::~Scene()
{

}

void Scene::boucle()
{
	Shader s("Shaders/Shader.vert", "Shaders/Shader.frag");
	Map p;
	
    m_projection = glm::perspective(70.0, (double) getSize().x / getSize().y, 1.0, 3000.0);
    m_modelview = glm::mat4(1.0);
	
	int i(0);
    while (m_event.isRunning())
    {
    	i++;
    	m_event.update();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		m_modelview = glm::lookAt(glm::vec3(15,15,15), glm::vec3(0,0,0), glm::vec3(0,0,1));
		
		m_modelview = glm::rotate(m_modelview, i/100.0f, glm::vec3(0,0,1));
		
		p.afficher(m_modelview, m_projection);
        glUseProgram(0);
        
        display();
        
        //m_event.stop();
    }
    
    Cube::erase();
}

void Scene::changeViewPort(int x, int y)
{
	glViewport(0, 0, x, y);
}



















