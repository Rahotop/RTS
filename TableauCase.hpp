#ifndef TABLEAU_CASE_HPP_DEFINE
#define TABLEAU_CASE_HPP_DEFINE

#include "Case.hpp"

class TableauCase
{

	public:
	
	TableauCase();
	TableauCase(int taille, float couleur[3]);
	~TableauCase();
	void addCase(int x, int y);
	void addCase(const Case& c);
	void initVBO();
	GLuint getVBO();
	GLuint* c_tab();
	
	int getTaille();
	int getSizeof();
	
	TableauCase& operator=(const TableauCase& t);
	
	private:
	
	Case *m_tab_c;
	int m_taille;
	float *m_couleur;
	GLuint *m_tabGL;
	int m_tmpRemplissage;
	GLuint m_vbo;
};

#endif
