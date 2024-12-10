#pragma once


// What is GLFW --> Graphics Library FrameWork
// How to draw Graphic : (1) window, (2)context, (3)handler
// OS마다 (1) (2) (3)을 만드는 방법이 다름 --> 이에 관한 추상화된 방법을 제공하는 OpenGL
// GLFW는 window 생성, context 생성 관리, 입력 처리 등을 받기 위한 플랫폼에 맞는 기능을 제공(멀티 플랫폼)

#define GLFW_INCLUDE_VULKAN // glfw가 Vulkan header를 포함하기 위해 정의 (GLFW header include 이전에 define)
#include <GLFW/glfw3.h>
#include <string>

#include <iostream>
#include <vector>
#include <fstream>

#include "FileUtils.h"


namespace LumiDynEngine {
	
	class AppBase {
	public:
		// window 관련 variable들
		int m_screenWidth;
		int m_screenHeight;
		std::string windowName;
		GLFWwindow* m_window;

		// Vulkan Instance variable 들
		VkInstance instance;
		VkPhysicalDevice physcialDevice;

		VkSurfaceKHR surface; // 플랫폼 독립적으로 랜더링된 이미지를 관리해줄 수 있는 객체

	public:
		AppBase();
		virtual ~AppBase();
		
		int Run(); // 작동

		virtual bool Initialize();

	protected:

		bool InitWindow();
		bool ShouldClose();

		bool InitVulkan();
		void CreateInstance();
		void createSurface(); // Rendering 이미지를 관리할 객체
		void createGraphicsPipeline();

		void cleanupInstance();
		void cleanUpSurface();
		void pickPhysicalDevice();
		bool isDeviceSuitable(VkPhysicalDevice device);

		void MainLoop();
		void CleanUp();
		

	};

}
