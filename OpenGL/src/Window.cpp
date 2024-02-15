#include "Window.h"

namespace Window
{
	GLFWwindow* window;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::Init(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
}

void Window::PollEventsAndSwapBuffers()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Window::ShouldWindowClose()
{
	return glfwWindowShouldClose(window);
}
