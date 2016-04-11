#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED

class Objet
{
	public:
	
	virtual void afficher(glm::mat4 modelview, glm::mat4 projection) = 0;
};

#endif
