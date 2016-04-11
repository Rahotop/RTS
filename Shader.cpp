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
	GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &codeSourceVertexGL, nullptr);
	glCompileShader(vertexID);
	
	//Get log vertex
	GLint log_length;
	glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &log_length);
	GLchar *log = new GLchar[log_length];
	
	glGetShaderInfoLog(vertexID, log_length, nullptr, log);
	
	std::cout << log << std::endl;
	
	delete[] log;
	
	//Fragment shader
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &codeSourceFragmentGL, nullptr);
	glCompileShader(fragmentID);
	
	//Get log Fragment
	glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &log_length);
	log = new GLchar[log_length];
	
	glGetShaderInfoLog(fragmentID, log_length, nullptr, log);
	
	std::cout << log << std::endl;
	
	//Program shader
	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexID);
	glAttachShader(m_programID, fragmentID);
	glLinkProgram(m_programID);
	
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

Shader::~Shader()
{
	glDeleteProgram(m_programID);
}

GLuint Shader::getID()
{
	return m_programID;
}

