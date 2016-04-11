#include "Map.hpp"

Map::Map() : m_tabC(new TableauCase[1]), m_shaderMap("Shaders/Map.vert", "Shaders/Map.frag")
{
	float tmp[3] = {1.0,0.0,0.0};
	m_tabC[0] = TableauCase(3, tmp);
	
	m_tabC[0].addCase(0,0);
	m_tabC[0].addCase(1,0);
	m_tabC[0].addCase(0,1);
	//m_tabC[0].addCase(1,1);
	
	m_tabC[0].initVBO();
}

Map::~Map()
{
	delete[] m_tabC;
}

void Map::afficher(glm::mat4 modelview, glm::mat4 projection)
{
	glUseProgram(m_shaderMap.getID());
		
            glBindBuffer(GL_ARRAY_BUFFER, Cube::getVBO());

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(0);
                
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::getVBOI());
				
				GLuint bindingPoint = 0;
				GLint index = glGetUniformBlockIndex(m_shaderMap.getID(), "pos");
				glUniformBlockBinding(m_shaderMap.getID(), index, bindingPoint);
				
                glBindBufferRange(GL_UNIFORM_BUFFER, bindingPoint, m_tabC[0].getVBO(), 0, 3);
					
					//glUniform1uiv(3,4,m_tabC[0].c_tab());
	                glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(projection));
	                glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(modelview));
	                glUniform3f(2, 1.0, 1.0f, 1.0);
					
					glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0, 3);
				
				glDisableVertexAttribArray(0);
				
			glBindBuffer(GL_ARRAY_BUFFER, 0);
}
