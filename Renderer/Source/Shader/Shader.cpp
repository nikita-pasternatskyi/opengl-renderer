#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();		
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    CreateShader(&vertex, vShaderCode, GL_VERTEX_SHADER);
    CreateShader(&fragment, fShaderCode, GL_FRAGMENT_SHADER);

    CreateShaderProgram(&ID, vertex, fragment);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::CreateShader(unsigned int* vShader, const char* source, unsigned int shaderType)
{
    *vShader = glCreateShader(shaderType);
    glShaderSource(*vShader, 1, &source, NULL); //upload the source
    glCompileShader(*vShader); //compile it

    int  success;
    char infoLog[512];
    glGetShaderiv(*vShader, GL_COMPILE_STATUS, &success); //check for errors
    if(!success)
    {
        glGetShaderInfoLog(*vShader, 512, NULL, infoLog); //display all of the errors
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::CreateShaderProgram(unsigned int* shaderProgram, unsigned int& vertexShader, unsigned int& fragmentShader)
{
    *shaderProgram = glCreateProgram();
    glAttachShader(*shaderProgram, vertexShader);
    glAttachShader(*shaderProgram, fragmentShader);
    glLinkProgram(*shaderProgram);

    int  success;
    char infoLog[512];
    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success); //check for errors
    if(!success)
    {
        glGetProgramInfoLog(*shaderProgram, 512, NULL, infoLog); //display all of the errors
        std::cout << "ERROR::SHADER::LINKING_FAIL\n" << infoLog << std::endl;
    }
}