#include "Map.hpp"
#include "Scene.hpp"

//constructeur par defaut, pour les tests
Map::Map() : m_tabC(new TableauCase[1]), m_shaderMap("Shaders/Map.vert", "Shaders/Map.frag"), m_x(20), m_y(20), m_nbTab(1), m_bindingPoint(0), m_cursor() //Utilisation du shader de la map
{
	m_tabC[0] = TableauCase(m_x*m_y); //Déclaration d'un tableauCase pour la couleur
	
	for(unsigned int i(0); i < m_x; i++)
	{
		for(unsigned int j(0); j < m_y; j++)
		{
			m_tabC[0].addCase(255, 255, 255, 1); //Ajout des cases, pour avoir un plan
		}
	}
	
	m_tabC[0].initUBO(); //Initialisation des positions dans un buffer
	
	GLint index = glGetUniformBlockIndex(m_shaderMap.getID(), "param");
	glUniformBlockBinding(m_shaderMap.getID(), index, m_bindingPoint);
	
	Objet::setMap(this);
}

Map::Map(std::string path) : m_tabC(nullptr), m_shaderMap("Shaders/Map.vert", "Shaders/Map.frag"), m_x(0), m_y(0), m_nbTab(0), m_bindingPoint(0), m_cursor()
{
	std::ifstream in(path.c_str());
	
	in >> m_x >> m_y;
	
	m_nbTab = (m_x/100)*(m_y/100);
	m_tabC = new TableauCase[m_nbTab];
	
	for(unsigned int i(0); i < m_nbTab; i++)
	{
		m_tabC[i] = TableauCase(10000);
		m_tabC[i].setOffset((i%(m_x/100))*200, (i/(m_x/100))*200);
	}
	
	for(unsigned int i(0); i < m_x; i++)
	{
		for(unsigned int j(0); j < m_y; j++)
		{
			int r,v,b,h;
			in >> r >> v >> b >> h;
			m_tabC[((i/100)+((j/100)*(m_x/100)))].addCase(r,v,b,h);
		}
	}
	
	
	for(unsigned int i(0); i < m_nbTab; i++)
	{
		m_tabC[i].initUBO();
	}
	
	GLint index = glGetUniformBlockIndex(m_shaderMap.getID(), "param");
	glUniformBlockBinding(m_shaderMap.getID(), index, m_bindingPoint);
	
	Objet::setMap(this);
}

Map::~Map()
{
	delete[] m_tabC;
}

void Map::afficher(glm::mat4 modelview, glm::mat4 projection)
{
	glUseProgram(m_shaderMap.getID()); //On utilise le shader de la map
		
            glBindBuffer(GL_ARRAY_BUFFER, Cube::getVBO()); //Verrouillage du vbo des sommets

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //Utilisation du vbo pour les sommets
                glEnableVertexAttribArray(0);
                
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::getIBO()); //Verrouillage du ibo pour la définition des triangles
				
						
				        glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(projection)); //Envoi de la matrice de projection au shader
				        glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(modelview)); //Envoi de la matrice modelview au shader
				        
				        glUniform1i(4, m_cursor.getXint());
				        glUniform1i(5, m_cursor.getYint());
						
						for(unsigned int i(0); i < m_nbTab; i++)
						{
							//Initialisation du binding point
				
						    glBindBufferRange(GL_UNIFORM_BUFFER, m_bindingPoint, m_tabC[i].getUBO(), 0, m_tabC[i].getTaille()); //Utilisation du binding point avec le vbo des positions
					        glUniform1ui(2, m_tabC[i].getX());
					        glUniform1ui(3, m_tabC[i].getY());
						
							glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0, m_tabC[i].getTaille()); //Dessin des cubes instanciés
						}
					
					
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //On deverrouille le ibo
				
				glDisableVertexAttribArray(0); //On arrête d'utiliser le vbo
				
			glBindBuffer(GL_ARRAY_BUFFER, 0); //On deverrouille le vbo
	
	//On arrête d'utiliser le shader dans la fonction appelante
}

void Map::update(Event & e)
{
	selectionFleche(e);
}

void Map::selectionFleche(Event & e)
{
	if(e.getTouche()[Touche::UP] && (unsigned int)e.getCursor().getYint() < m_y-1)
	{
		e.setCursor(e.getCursor() + Position(0,1));
	}
	if(e.getTouche()[Touche::DOWN] && e.getCursor().getYint() > 0)
	{
		e.setCursor(e.getCursor() + Position(0,-1));
	}
	if(e.getTouche()[Touche::RIGHT] && (unsigned int)e.getCursor().getXint() < m_x-1)
	{
		e.setCursor(e.getCursor() + Position(1,0));
	}
	if(e.getTouche()[Touche::LEFT] && e.getCursor().getXint() > 0)
	{
		e.setCursor(e.getCursor() + Position(-1,0));
	}
	
	m_cursor = e.getCursor();
	
	e.getTouche()[Touche::UP] = false;
	e.getTouche()[Touche::DOWN] = false;
	e.getTouche()[Touche::RIGHT] = false;
	e.getTouche()[Touche::LEFT] = false;
}

unsigned int Map::getHauteur(int x, int y)
{
	int offsetX = x/100;
	int offsetY = y/100;
	
	int tmpX = x%100;
	int tmpY = y%100;
	
	int maxX = m_x/100;
	
	return m_tabC[offsetX+offsetY*maxX].getCase(tmpY+tmpX*100).getPar() % 256;
}








