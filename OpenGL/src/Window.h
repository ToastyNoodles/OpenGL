#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Window
{
	void Init(int width, int height, const char* title);
	void PollEventsAndSwapBuffers();
	bool ShouldWindowClose();
}