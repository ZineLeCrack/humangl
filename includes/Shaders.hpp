#pragma once

#include "Includes.hpp"

class Shaders
{
	public:

		GLuint shaderProgram;

	public:

		Shaders(string vertexFilePath, string fragmentFilePath);
		string readShaderFile(string filePath);
		GLuint compileShader(string filePath, GLenum type);
		~Shaders();
};
