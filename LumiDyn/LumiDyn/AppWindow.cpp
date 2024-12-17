#include "AppWindow.h"
#include <stdexcept>  
#include <iostream>   

namespace LumiDynEngine {

	void Window::init() {

		// GLFW 라이브러리 초기화
		if (!glfwInit()) {
			throw std::runtime_error("Failed to initialize GLFW");
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
		if (!window) {
			throw std::runtime_error("Failed to create GLFW window");
		}
		std::cout << "Window initialized: " << width << "x" << height << std::endl;
	}

	void Window::cleanup() {
		if (window) {
			glfwDestroyWindow(window);  // 창 제거
			window = nullptr;
		}
	}


	GLFWwindow* Window::getWindow() { return window; }

}