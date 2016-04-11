#include "TableauCase.hpp"

TableauCase::TableauCase() : m_tab_c(nullptr), m_taille(0), m_couleur(nullptr), m_tabGL(nullptr), m_tmpRemplissage(0), m_vbo(0)
{

}

TableauCase::TableauCase(int taille, float couleur[3]): m_tab_c(new Case[taille]), m_taille(taille), m_couleur(new float[3]), m_tabGL(new GLuint[taille]), m_tmpRemplissage(0), m_vbo(0)
{
	for(int i(0);i<3;i++)
		m_couleur[i] = couleur[i];
}

TableauCase::~TableauCase()
{
	delete[] m_tab_c;
	delete[] m_couleur;
	delete[] m_tabGL;
	glDeleteBuffers(1, &m_vbo);
}

void TableauCase::addCase(int x, int y)
{
	if(m_tmpRemplissage < m_taille)
	{
		m_tab_c[m_tmpRemplissage] = Case(x,y);
		m_tabGL[m_tmpRemplissage] = m_tab_c[m_tmpRemplissage].getPos();
		m_tmpRemplissage++;
	}
}

void TableauCase::addCase(const Case& c)
{
	if(m_tmpRemplissage < m_taille)
	{
		m_tab_c[m_tmpRemplissage] = c;
		m_tabGL[m_tmpRemplissage] = m_tab_c[m_tmpRemplissage].getPos();
		m_tmpRemplissage++;
	}
}

void TableauCase::initVBO()
{
	glGenBuffers(1, &m_vbo); //Generation VBO

    glBindBuffer(GL_UNIFORM_BUFFER, m_vbo); //Verrouillage VBO

        glBufferData(GL_UNIFORM_BUFFER, m_taille * sizeof(GLuint), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_UNIFORM_BUFFER, 0, m_taille * sizeof(GLuint), m_tabGL); //Transfert données

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

GLuint TableauCase::getVBO()
{
	return m_vbo;
}

GLuint* TableauCase::c_tab()
{
	return m_tabGL;
}

int TableauCase::getTaille()
{
	return m_taille;
}

int TableauCase::getSizeof()
{
	return sizeof(GLuint) * m_taille;
}

TableauCase& TableauCase::operator=(const TableauCase& t)
{
	if(m_tab_c != nullptr)
		delete[] m_tab_c;
	m_tab_c = new Case[t.m_taille];
	
	if(m_couleur == nullptr)
		m_couleur = new float[3];
	
	if(m_tabGL != nullptr)
		delete[] m_tabGL;
	m_tabGL = new GLuint[t.m_taille];
	
	m_taille = t.m_taille;
	
	m_tmpRemplissage = t.m_tmpRemplissage;
	
	for(int i(0); i < m_tmpRemplissage; i++)
	{
		m_tab_c[i] = t.m_tab_c[i];
		m_tabGL[i] = t.m_tabGL[i];
		if(i < 3)
			m_couleur[i] = t.m_couleur[i];
	}
}























