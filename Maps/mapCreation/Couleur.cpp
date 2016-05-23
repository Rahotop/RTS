#include "Couleur.hpp"

Couleur::Couleur(int r, int v, int b) : m_r(r), m_v(v), m_b(b)
{

}

Couleur::Couleur(const Couleur & c) : m_r(c.m_r), m_v(c.m_v), m_b(c.m_b)
{

}

int Couleur::getR()
{
    return m_r;
}

int Couleur::getV()
{
    return m_v;
}

int Couleur::getB()
{
    return m_b;
}
