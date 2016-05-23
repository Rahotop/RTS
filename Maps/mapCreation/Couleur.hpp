#ifndef COULEUR_HPP_INCLUDED
#define COULEUR_HPP_INCLUDED

class Couleur
{
    public:

    Couleur(int r, int v, int b);
    Couleur(const Couleur & c);
    int getR();
    int getV();
    int getB();

    private:

    int m_r,m_v,m_b;

};

#endif
