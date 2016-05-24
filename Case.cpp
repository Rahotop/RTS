#include "Case.hpp"

//Construsteur par défaut avec la couleur 0,0,0 et la hauteur 1
Case::Case() : m_par(1)
{

}

//Constructeur qui initialise la couleur avec rgb(r,v,b) et la hauteur avec h
//m_par contiendra les informations sur la position comme suit :
//rrrr.rrrr vvvv.vvvv bbbb.bbbb hhhh.hhhh
//Les deux premiers octets représentent x et les deux derniers y
Case::Case(unsigned int r, unsigned int v, unsigned int b, unsigned int h) : m_par((r << 24)+((v << 24) >> 8)+((b << 24) >> 16)+((h%256)))
{
	//std::cout << "(" << (m_par >> 24) << ";" << ((m_par << 8) >> 24) << ";" << ((m_par << 16) >> 24) << ") " << m_par%256 << std::endl;
}

//Constructeur par copie
Case::Case(const Case& c) : m_par(c.m_par)
{
	
}

//Accesseur sur les paramètres de la case
GLuint Case::getPar()
{
	return m_par;
}

void Case::setPar(unsigned int r, unsigned int v, unsigned int b, unsigned int h)
{
	m_par=(r << 24)+((v << 24) >> 8)+((b << 24) >> 16)+((h%256));
}

//Surcharge de l'operateur =
Case& Case::operator=(const Case& c)
{
	m_par = c.m_par;
	
	return *this;
}

