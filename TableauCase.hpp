#ifndef TABLEAU_CASE_HPP_DEFINE
#define TABLEAU_CASE_HPP_DEFINE

#include "Case.hpp"

class TableauCase
{

	public:
	
	//Constructeur par defaut
	TableauCase();
	//Constructeur qui prend en parametre sa taille
	TableauCase(int taille);
	~TableauCase();
	//Ajout de case
	void addCase(unsigned int r, unsigned int v, unsigned int b, unsigned int h);
	void addCase(const Case& c);
	void initUBO(); //Initialisation de l'ubo
	GLuint getUBO(); //Accesseur à l'ubo
	
	void setOffset(int x, int y);
	
	int getTaille();
	int getSizeof();
	int getX();
	int getY();
	Case getCase(int i);
	
	//Surcharge de l'operateur =
	TableauCase& operator=(const TableauCase& t);
	
	private:
	
	Case *m_tab_c;
	int m_taille;
	GLuint *m_tabGL;
	int m_tmpRemplissage;
	GLuint m_ubo;
	
	//offsets
	int m_x;
	int m_y;
};

#endif
