#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/ext/matrix_float4x4.hpp>
#include "ShaderLoader.h"

class Shader {
public:
    unsigned int ID;

    Shader(const std::string& vertexPath, const std::string& fragmentPath) {
        std::string vertexCode = ShaderLoader::loadShaderFromFile(vertexPath);
        std::string fragmentCode = ShaderLoader::loadShaderFromFile(fragmentPath);

        if (vertexCode.empty() || fragmentCode.empty()) {
            std::cerr << "ERROR: Shader source is empty!" << std::endl;
            return;
        }

        unsigned int vertex, fragment;

        // Compile Vertex Shader
        vertex = compileShader(GL_VERTEX_SHADER, vertexCode);
        fragment = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

        // Link Shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        // Cleanup
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void use() { glUseProgram(ID); }

    void setMat4(const std::string& name, const glm::mat4& mat) {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void setVec3(const std::string& name, const glm::vec3& value) const {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
    }

    int getID() {
        return ID;
    }

private:
    unsigned int compileShader(GLenum type, const std::string& source) {
        unsigned int shader = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(shader, 1, &src, NULL);
        glCompileShader(shader);
        checkCompileErrors(shader, type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
        return shader;
    }

    void checkCompileErrors(unsigned int shader, std::string type) {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR: Shader Compilation (" << type << ")\n" << infoLog << std::endl;
            }
        }
        else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR: Program Linking\n" << infoLog << std::endl;
            }
        }
    }
};

#endif
