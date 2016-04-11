#ifndef CUBE_HPP_INCLUDED
#define CUBE_HPP_INCLUDED

//Bibliothèques nécessaires pour les types OpenGL
#include <GL/glew.h>
#include <GL/glut.h>

//Classe représentant un cube
//Beaucoup d'éléments statiques, car les vertices des cubes seront toujours les mêmes.
class Cube
{
	public:
	
	//Initialisation de tout les attributs statique pour être capable de dessiner un cube.
	static void init();
	//Accesseur au VBO (vertex buffer object)
	static GLuint getVBO();
	static GLuint getVBOI();
	static GLubyte* getIndices();
	static void erase();
	
	private:
	
	static float *m_vertices;
	static GLubyte *m_indices;
	static GLuint m_vbo;
	static GLuint m_vboI;
};

#endif
