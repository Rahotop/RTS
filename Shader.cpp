#include "Shader.hpp"

Shader::Shader(std::string vertexPath, std::string fragmentPath) : m_programID(0)
{
	//Get le code source
	std::ifstream vertex(vertexPath.c_str());
	std::ifstream fragment(fragmentPath.c_str());
	
    std::string ligne;
    std::string codeSourceVertex;
    std::string codeSourceFragment;

    while(getline(vertex, ligne))
        codeSourceVertex += ligne + '\n';
        
    while(getline(fragment, ligne))
        codeSourceFragment += ligne + '\n';
    
    const GLchar* codeSourceVertexGL = codeSourceVertex.c_str();
    const GLchar* codeSourceFragmentGL = codeSourceFragment.c_str();
	
	//Compilation
	
	//Vertex shader
	GLuint vertexID = glCreateShader(GL_VERTEX_SHADER); //On réserve un emplacement mémoire pour le shader
	glShaderSource(vertexID, 1, &codeSourceVertexGL, nullptr); //On transfert le code source
	glCompileShader(vertexID); //On compile
	
	//Get log vertex
	GLint log_length;
	glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &log_length);
	GLchar *log = new GLchar[log_length];
	
	glGetShaderInfoLog(vertexID, log_length, nullptr, log);
	
	std::cout << log << std::endl;
	
	delete[] log;
	
	//Fragment shader
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER); //On réserve un emplacement mémoire pour le shader
	glShaderSource(fragmentID, 1, &codeSourceFragmentGL, nullptr); //On transfert le code source
	glCompileShader(fragmentID); //On compile
	
	//Get log Fragment
	glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &log_length);
	log = new GLchar[log_length];
	
	glGetShaderInfoLog(fragmentID, log_length, nullptr, log);
	
	std::cout << log << std::endl;
	
	delete[] log;
	
	//Program shader
	m_programID = glCreateProgram(); //On creer un shader complet
	glAttachShader(m_programID, vertexID); //On attache le vertex shader
	glAttachShader(m_programID, fragmentID); //On attache le fragment shader
	glLinkProgram(m_programID); //On lie les differentes partie du shader
	
	glDeleteShader(vertexID); //On supprime le vertex shader inutile maintenant
	glDeleteShader(fragmentID); //On supprime le fragment shader inutile maintenant
}

Shader::~Shader()
{
	glDeleteProgram(m_programID); //On supprime le shader
}

GLuint Shader::getID()
{
	return m_programID; //On retourne l'id du shader
}

