#include "Shader.h"

std::string LoadShaderFile(const char* shaderFile)
{
	std::string content;
	std::ifstream fileStream(shaderFile, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << shaderFile << std::endl;
		return "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}

void Shader::Load(const char* vertexFilepath, const char* fragmentFilepath)
{
	int  success;
	char infoLog[512];

	std::string vertexShaderSource = LoadShaderFile(vertexFilepath);
	const char* vertexSource = vertexShaderSource.c_str();

	std::string fragmentShaderSource = LoadShaderFile(fragmentFilepath);
	const char* fragmentSource = fragmentShaderSource.c_str();

	uint32_t vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Vertex shader failed to compile shader.\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Fragment shader failed to compile shader.\n" << infoLog << std::endl;
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);

	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "Failed to link shaders to shader program.\n" << infoLog << std::endl;
	}

	std::cout << "Loaded Vertex Shader " << vertexFilepath << std::endl;
	std::cout << "Loaded Fragment Shader " << fragmentFilepath << std::endl;

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Bind()
{
	glUseProgram(id);
}
