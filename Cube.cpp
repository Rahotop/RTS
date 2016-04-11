#include "Cube.hpp"

float *Cube::m_vertices = nullptr;
GLuint Cube::m_vbo = 0;
GLubyte *Cube::m_indices = nullptr;
GLuint Cube::m_vboI = 0;

void Cube::init()
{
	int tailleV(24), tailleI(36);
	m_vertices = new float[tailleV];
	m_indices = new GLubyte[tailleI];
	float tmp[] = {	-1.0, -1.0, -1.0,	//0
					-1.0, -1.0, 1.0,	//1
					-1.0, 1.0, -1.0,	//2
					-1.0, 1.0, 1.0,		//3
					1.0, -1.0, -1.0,	//4
					1.0, -1.0, 1.0,		//5
					1.0, 1.0, -1.0,		//6
					1.0, 1.0, 1.0};		//7
	
	float tmpI[] = {	0, 1, 2,
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
	
	for(int i(0); i < tailleV; i++)
	{
		m_vertices[i] = tmp[i];
	}
	
	for(int i(0); i < tailleI; i++)
	{
		m_indices[i] = tmpI[i];
	}
	
	glGenBuffers(1, &m_vbo); //Generation VBO vertices

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Verrouillage VBO

        glBufferData(GL_ARRAY_BUFFER, tailleV * sizeof(float), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ARRAY_BUFFER, 0, tailleV * sizeof(float), m_vertices); //Transfert données
	
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
	glGenBuffers(1, &m_vboI); //Generation VBO indices

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboI); //Verrouillage VBO

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, tailleI * sizeof(GLubyte), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, tailleI * sizeof(GLubyte), m_indices); //Transfert données

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint Cube::getVBO()
{
	return m_vbo;
}

GLuint Cube::getVBOI()
{
	return m_vboI;
}

GLubyte* Cube::getIndices()
{
	return m_indices;
}

void Cube::erase()
{
	delete[] m_vertices;
	delete[] m_indices;
	
	GLuint tmp[2] = {m_vbo, m_vboI};
	
	glDeleteBuffers(2, tmp);
}
