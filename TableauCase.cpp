#include "TableauCase.hpp"

//Constructeur par defaut
TableauCase::TableauCase() : m_tab_c(nullptr), m_taille(0), m_tabGL(nullptr), m_tmpRemplissage(0), m_ubo(0), m_x(0), m_y(0)
{

}

//Constructeur qui prend en parametre la taille du tableau
TableauCase::TableauCase(int taille): m_tab_c(new Case[taille]), m_taille(taille), m_tabGL(new GLuint[taille]), m_tmpRemplissage(0), m_ubo(0), m_x(0), m_y(0)
{
	
}

TableauCase::~TableauCase()
{
	if(m_tab_c)
		delete[] m_tab_c;
	if(m_tabGL)
		delete[] m_tabGL;
	if(glIsBuffer(m_ubo))
		glDeleteBuffers(1, &m_ubo);
}

//On ajoute une case avec les paramètres (r,v,b) et h
void TableauCase::addCase(unsigned int r, unsigned int v, unsigned int b, unsigned int h)
{
	if(m_tmpRemplissage < m_taille)
	{
		m_tab_c[m_tmpRemplissage] = Case(r,v,b,h);
		m_tabGL[m_tmpRemplissage] = m_tab_c[m_tmpRemplissage].getPar();
		m_tmpRemplissage++;
	}
	else
	{
		std::cout << "no space" << std::endl;
	}
}

//On ajoute le cube pris en parametre
void TableauCase::addCase(const Case& c)
{
	if(m_tmpRemplissage < m_taille)
	{
		m_tab_c[m_tmpRemplissage] = c;
		m_tabGL[m_tmpRemplissage] = m_tab_c[m_tmpRemplissage].getPar();
		m_tmpRemplissage++;
	}
	else
	{
		std::cout << "no space" << std::endl;
	}
}

//Initialisation du ubo après avoir rempli le tableau
void TableauCase::initUBO()
{
	glGenBuffers(1, &m_ubo); //Generation UBO

    glBindBuffer(GL_UNIFORM_BUFFER, m_ubo); //Verrouillage UBO

        glBufferData(GL_UNIFORM_BUFFER, m_taille * sizeof(GLuint), 0, GL_STATIC_DRAW); //Allocation memoire

        glBufferSubData(GL_UNIFORM_BUFFER, 0, m_taille * sizeof(GLuint), m_tabGL); //Transfert données

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void TableauCase::setOffset(int x, int y)
{
	m_x = x;
	m_y = y;
}

GLuint TableauCase::getUBO()
{
	return m_ubo;
}

int TableauCase::getTaille()
{
	return m_taille;
}

int TableauCase::getSizeof()
{
	return sizeof(GLuint) * m_taille;
}

int TableauCase::getX()
{
	return m_x;
}

int TableauCase::getY()
{
	return m_y;
}

//Surcharge de l'operateur =
TableauCase& TableauCase::operator=(const TableauCase& t)
{
	//On supprime les partie dynamique si elles sont initialisées, et on les remplace avec les bonnes tailles
	if(m_tab_c != nullptr)
		delete[] m_tab_c;
	m_tab_c = new Case[t.m_taille];
	
	if(m_tabGL != nullptr)
		delete[] m_tabGL;
	m_tabGL = new GLuint[t.m_taille];
	
	m_taille = t.m_taille;
	
	m_tmpRemplissage = t.m_tmpRemplissage;
	
	//On copie les cases déjà remplies
	for(int i(0); i < m_tmpRemplissage; i++)
	{
		m_tab_c[i] = t.m_tab_c[i];
		m_tabGL[i] = t.m_tabGL[i];
	}
	
	return *this;
}


Case TableauCase::getCase(int i)
{
	return m_tab_c[i];
}







