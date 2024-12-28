#pragma once
#include <string>

class Shader
{
public:
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    // use/activate the shader
    void Use();
    // utility uniform functions
    void SetBool(const std::string &name, bool value) const;  
    void SetInt(const std::string &name, int value) const;   
    void SetFloat(const std::string &name, float value) const;

private:    
    void CreateShader(unsigned int* vShader, const char* source, unsigned int shaderType);
    void CreateShaderProgram(unsigned int* shaderProgram, unsigned int& vertexShader, unsigned int& fragmentShader);
};