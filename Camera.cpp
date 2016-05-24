#include "Camera.hpp"
#include "Scene.hpp"

Camera::Camera(int xC, int yC, int zC, int xL, int yL, int zL) : m_posCamera(xC,yC,zC), m_posLook(xL,yL,zL)
{
	m_vecRegard = glm::vec3(xL-xC, yL-yC, zL-zC);
}

Camera::Camera(glm::vec3 posCamera, glm::vec3 posLook) : m_posCamera(posCamera), m_posLook(posLook)
{

}

glm::vec3 Camera::getCamera()
{
	return m_posCamera;
}

glm::vec3 Camera::getLook()
{
	return m_posLook;
}

glm::vec3 Camera::getVec()
{
	return m_vecRegard;
}

void Camera::setLook(int x, int y, int z)
{
	m_posLook=glm::vec3(x,y,z);
	m_vecRegard = m_posLook - m_posCamera;
}

void Camera::setCamera(int x, int y, int z)
{
	m_posCamera=glm::vec3(x,y,z);
}

void Camera::setVec(int x, int y, int z)
{
	m_vecRegard=glm::vec3(x,y,z);
	m_posLook = m_posCamera + m_vecRegard;
}

void Camera::zoom(Event & e)
{
	glm::vec3 vec(m_vecRegard);
	vec.x /= m_vecRegard.z;
	vec.y /= m_vecRegard.z;
	vec.z /= m_vecRegard.z;
	if(m_posCamera.z <= 5000 && m_posCamera.z >= 50)
	{
		if(e.getDeltaWheel()==1)
		{
			m_posCamera.x -= vec.x*10;
			m_posCamera.y -= vec.y*10;
			m_posCamera.z -= vec.z*10;
			e.setDeltaWheel(0);
		}
		else if (e.getDeltaWheel()==-1)
		{
			m_posCamera.x += vec.x*10;
			m_posCamera.y += vec.y*10;
			m_posCamera.z += vec.z*10;
			e.setDeltaWheel(0);
		}
	}
	else if(m_posCamera.z > 500)
	{
		m_posCamera.x -= vec.x;
		m_posCamera.y -= vec.y;
		m_posCamera.z -= vec.z;
	}
	else if(m_posCamera.z < 50)
	{
		m_posCamera.x += vec.x;
		m_posCamera.y += vec.y;
		m_posCamera.z += vec.z;
	}
}

void Camera::deplacement(Event & e)
{
	if((unsigned int)e.getMouseX() > (e.getWin()->getSize().x)-20)
	{
		m_posCamera.x += 1;
		m_posCamera.y -= 1;
		
		m_posLook.x += 1;
		m_posLook.y -= 1;		
	}
	if(e.getMouseX() < 20)
	{
		m_posCamera.x -= 1;
		m_posCamera.y += 1;
		
		m_posLook.x -= 1;
		m_posLook.y += 1;
	}
	if((unsigned int)e.getMouseY() > (e.getWin()->getSize().y)-20)
	{
		m_posCamera.y -= 1;
		m_posCamera.x -= 1;
		
		m_posLook.y -= 1;
		m_posLook.x -= 1;
	}
	if(e.getMouseY() < 20)
	{
		m_posCamera.y += 1;
		m_posCamera.x += 1;
		
		m_posLook.y += 1;
		m_posLook.x += 1;
	}
}

void Camera::update(Event & e)
{
	zoom(e);
	deplacement(e);
}

glm::mat4 Camera::lookAt()
{
	return glm::lookAt(m_posCamera, m_posCamera + m_vecRegard, glm::vec3(0,0,1));
}
