#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Map;

//Classe virtuelle représentant un objet affichable
class Objet
{
	public:
	
	//Methode à surcharger pour les affichable
	virtual void afficher(glm::mat4 modelview, glm::mat4 projection) = 0;
	
	inline static void setMap(Map *m) { s_map = m; }
	
	protected:
	
	static Map *s_map;
};

#endif
