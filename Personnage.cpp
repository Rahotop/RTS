#include "Personnage.hpp"

Personnage::Personnage(std::string path) : m_shaderPerso("Shaders/Personnage.vert", "Shaders/Personnage.frag"),m_vertices(nullptr), m_indices(nullptr), m_color(nullptr), m_vbo(0), m_ibo(0), m_tailleI(0), m_bindingPoint(0), m_offsetColor(0)
{
	//FICHIER
	std::ifstream in(path.c_str());
	
	
	//Taille du tableau de vertex, et déclaration du tableau
	int tailleV(0);
	
	in >> tailleV;
	tailleV *= 3;
	
	m_offsetColor = tailleV * sizeof(float);
	
	m_vertices = new float[tailleV];
	
	//Copie des valeurs du fichier vers le tableau memoire
	for(int i(0); i < tailleV; i++)
	{
		in >> m_vertices[i];
	}
	
	//Taille du tableau des indices, et déclaration du tableau
	
	in >> m_tailleI;
	m_tailleI *= 3;
	
	m_indices = new GLubyte[m_tailleI];
	
	//Copie des valeurs du fichier vers le tableau memoire
	for(int i(0); i < m_tailleI; i++)
	{
		int tmp;
		in >> tmp;
		m_indices[i] = tmp;
	}
	
	m_color = new float[tailleV];
	
	for(int i(0); i < tailleV; i++)
	{
		in >> m_color[i];
		m_color[i] /= 255.0;
	}
	
	//INITIALISATION POUR SHADER
	
	
	
	glGenBuffers(1, &m_vbo); //Generation VBO (vertices + couleurs)

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Verrouillage VBO

        glBufferData(GL_ARRAY_BUFFER, (tailleV*2* sizeof(float)), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ARRAY_BUFFER, 0, tailleV * sizeof(float), m_vertices); //Transfert données vertices
        
        glBufferSubData(GL_ARRAY_BUFFER, tailleV * sizeof(float), tailleV * sizeof(float), m_color); //Transfert données couleurs
	
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
	glGenBuffers(1, &m_ibo); //Generation IBO (indices)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo); //Verrouillage IBO

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_tailleI * sizeof(GLubyte), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_tailleI * sizeof(GLubyte), m_indices); //Transfert données

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    //Binding point
    
	GLint index = glGetUniformBlockIndex(m_shaderPerso.getID(), "param");
	glUniformBlockBinding(m_shaderPerso.getID(), index, m_bindingPoint);
}

Personnage::~Personnage()
{
	//Suppression des tableaux de valeurs
	delete[] m_vertices;
	delete[] m_indices;
	delete[] m_color;
	
	//Suppression de  tableaux de la VRAM
	
	GLuint tmp[2] = {m_vbo, m_ibo};
	
	glDeleteBuffers(2, tmp);
}

void Personnage::setElem(int id, const Position& p)
{
	m_mapPos[id] = p;
}

void Personnage::eraseElem(int id)
{
	m_mapPos.erase(id);
}

int Personnage::count(int id)
{
	return m_mapPos.count(id);
}

void Personnage::afficher(glm::mat4 modelview, glm::mat4 projection)
{
	glUseProgram(m_shaderPerso.getID()); //On utilise le shader de la map
		
            glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Verrouillage du vbo des sommets

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0)); //Utilisation du vbo pour les sommets
                glEnableVertexAttribArray(0);
                	
				    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_offsetColor));
				    glEnableVertexAttribArray(1);
                	
						glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo); //Verrouillage du ibo pour la définition des triangles
						
					
						    glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(projection)); //Envoi de la matrice de projection au shader
						    glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(modelview)); //Envoi de la matrice modelview au shader
						
							for( auto &x : m_mapPos)
							{
								glUniform1f(2, x.second.getX());
								glUniform1f(3, x.second.getY());
								glUniform1ui(4, s_map->getHauteur(x.second.getXint(),x.second.getYint()));
							
								glDrawElements(GL_TRIANGLES, m_tailleI, GL_UNSIGNED_BYTE, 0);
							}
						
					
						glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //On deverrouille le ibo
					
				    glDisableVertexAttribArray(1);
					
				glDisableVertexAttribArray(0); //On arrête d'utiliser le vbo
				
			glBindBuffer(GL_ARRAY_BUFFER, 0); //On deverrouille le vbo
	
	//On arrête d'utiliser le shader dans la fonction appelante
}











