#include "Case.hpp"

//Construsteur par défaut à la position 0,0
Case::Case() : m_pos(0)
{

}

//Constructeur qui initialise la position en x,y
//m_pos contiendra les informations sur la position comme suit :
//xxxx.xxxx xxxx.xxxx yyyy.yyyy yyyy.yyyy
//Les deux premiers octets représentent x et les deux derniers y
Case::Case(unsigned int x, unsigned int y) : m_pos(((unsigned int)x << 16)+(((unsigned int)y << 16) >> 16))
{

}

//Constructeur par copie
Case::Case(const Case& c) : m_pos(c.m_pos)
{
	
}

//Accesseur sur la position
GLuint Case::getPos()
{
	return m_pos;
}

//Surcharge de l'operateur =
Case& Case::operator=(const Case& c)
{
	m_pos = c.m_pos;
}

