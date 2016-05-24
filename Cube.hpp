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
	//Accesseur au IBO (indices buffer object)
	static GLuint getIBO();
	//Accesseur du tableau des indices.
	static GLubyte* getIndices();
	//Suppression de tout les éléments dynamiques statiques.
	static void erase();
	
	private:
	
	//Tableau des sommets dans la RAM
	static float *m_vertices;
	//Tableau des indices dans la RAM
	static GLubyte *m_indices;
	//Pointeur vers les sommets dans la VRAM
	static GLuint m_vbo;
	//Pointeur vers les indices dans la VRAM
	static GLuint m_ibo;
};

#endif
