#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Event.hpp"

class Camera
{

	public:
	
	Camera(int xC, int yC, int zC, int xL, int yL, int zL);
	Camera(glm::vec3 posCamera, glm::vec3 posLook);
	
	glm::vec3 getCamera();
	glm::vec3 getLook();
	glm::vec3 getVec();
	
	void setCamera(int x, int y, int z);
	void setLook(int x, int y, int z);
	void setVec(int x, int y, int z);
	
	void zoom(Event & e);
	void deplacement(Event & e);
	void update(Event & e);
	
	glm::mat4 lookAt();
	
	private:
		
	glm::vec3 m_posCamera;
	glm::vec3 m_posLook;
	glm::vec3 m_vecRegard;

};

#endif
