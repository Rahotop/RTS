#include "Cube.hpp"

//Initialisation des attributs au début de l'execution du programme
float *Cube::m_vertices = nullptr;
GLuint Cube::m_vbo = 0;
GLubyte *Cube::m_indices = nullptr;
GLuint Cube::m_ibo = 0;

//Initialisation de tout les attributs statique pour être capable de dessiner un cube.
void Cube::init()
{
	if(m_vertices)
		delete[] m_vertices;
	if(m_indices)
		delete[] m_indices;
	if(glIsBuffer(m_vbo) == GL_TRUE)
		glDeleteBuffers(1, &m_vbo);
	if(glIsBuffer(m_ibo) == GL_TRUE)
		glDeleteBuffers(1, &m_ibo);
	
	//Taille des tableaux des vertex et des indices
	int tailleV(24), tailleI(36);
	//Création des tableau dynamiquement
	m_vertices = new float[tailleV];
	m_indices = new GLubyte[tailleI];
	//Tableau temporaire des sommets
	float tmp[] = {	-1.0, -1.0, -1.0,	//0
					-1.0, -1.0, 1.0,	//1
					-1.0, 1.0, -1.0,	//2
					-1.0, 1.0, 1.0,		//3
					1.0, -1.0, -1.0,	//4
					1.0, -1.0, 1.0,		//5
					1.0, 1.0, -1.0,		//6
					1.0, 1.0, 1.0};		//7
	//Tableau temporaire des indices
	GLubyte tmpI[] = {	0, 1, 2,
						1, 3, 2,
						0, 4, 1,
						1, 4, 5,
						4, 6, 5,
						5, 6, 7,
						2, 3, 6,
						3, 7, 6,
						1, 5, 7,
						1, 7, 3,
						0, 6, 4,
						0, 2, 6};
	
	//Copie du tableau temporaire vers le tableau de classe des sommets
	for(int i(0); i < tailleV; i++)
	{
		m_vertices[i] = tmp[i];
	}
	
	//Copie du tableau temporaire vers le tableau de classe des indices
	for(int i(0); i < tailleI; i++)
	{
		m_indices[i] = tmpI[i];
	}
	
	glGenBuffers(1, &m_vbo); //Generation VBO (vertices)

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Verrouillage VBO

        glBufferData(GL_ARRAY_BUFFER, tailleV * sizeof(float), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ARRAY_BUFFER, 0, tailleV * sizeof(float), m_vertices); //Transfert données
	
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
	glGenBuffers(1, &m_ibo); //Generation IBO (indices)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo); //Verrouillage IBO

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, tailleI * sizeof(GLubyte), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, tailleI * sizeof(GLubyte), m_indices); //Transfert données

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Accesseur au vbo
GLuint Cube::getVBO()
{
	return m_vbo;
}

//Accesseur au ibo
GLuint Cube::getIBO()
{
	return m_ibo;
}

//Accesseur au tableau d'indices
GLubyte* Cube::getIndices()
{
	return m_indices;
}

//Suppression de tout les éléments dynamiques statiques.
void Cube::erase()
{
	delete[] m_vertices;
	delete[] m_indices;
	
	GLuint tmp[2] = {m_vbo, m_ibo};
	
	glDeleteBuffers(2, tmp);
}




