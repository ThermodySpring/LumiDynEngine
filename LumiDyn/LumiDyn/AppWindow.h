#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace LumiDynEngine {

	class Window {
	private:
		uint32_t width = 800;
		uint32_t height = 600;

		GLFWwindow* window;

		void init();
		void cleanup();

		Window();           // 持失切
		~Window();          // 社瑚切

		GLFWwindow* getWindow();
	};

}