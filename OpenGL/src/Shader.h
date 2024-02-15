#pragma once
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <string>

class Shader
{
public:
	void Load(const char* vertexFilepath, const char* fragmentFilepath);
	void Bind();
private:
	uint32_t id;
};