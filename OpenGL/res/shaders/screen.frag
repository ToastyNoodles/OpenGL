#version 330 core
out vec4 FragColor;

in vec2 fTexCoord;

void main()
{
	FragColor = vec4(fTexCoord, 0.0f, 1.0);
}