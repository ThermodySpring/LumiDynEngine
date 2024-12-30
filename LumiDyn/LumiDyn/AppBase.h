#pragma once

// What is GLFW --> Graphics Library FrameWork
// How to draw Graphic : (1) window, (2)context, (3)handler
// OS마다 (1) (2) (3)을 만드는 방법이 다름 --> 이에 관한 추상화된 방법을 제공하는 OpenGL
// GLFW는 window 생성, context 생성 관리, 입력 처리 등을 받기 위한 플랫폼에 맞는 기능을 제공(멀티 플랫폼)

#define VK_USE_PLATFORM_WIN32_KHR

#define GLFW_INCLUDE_VULKAN // glfw가 Vulkan header를 포함하기 위해 정의 (GLFW header include 이전에 define)
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#undef max

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"

#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <map>
#include <set>

#include <cstdint>
#include <limits>

#include <algorithm>

#include "FileUtils.h"
#include <optional>

#include "InstanceManager.h"



namespace LumiDynEngine {

	const int MAX_FRAMES_IN_FLIGHT = 2;
	
	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

	class AppBase {
	public:

		Vulkan::InstanceManager instanceManager;
		// window 관련 variable들
		
		int m_screenWidth;
		int m_screenHeight;
		std::string windowName;
		GLFWwindow* m_window;

		// Vulkan Instance variable 들
		VkInstance instance;

		VkSurfaceKHR surface; // 플랫폼 독립적으로 랜더링된 이미지를 관리해줄 수 있는 객체

		// Handler
		// VkPhysicalDevice

		// QueueFamily
		struct QueueFamilyIndices {
			std::optional<uint32_t> graphicsFamily;
			std::optional<uint32_t> presentFamily;

			bool isComplete() {
				return graphicsFamily.has_value() && presentFamily.has_value();
			}
		};
		
		// handler
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkDevice device;

		VkQueue graphicsQueue;
		VkQueue presentQueue;

		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
		std::vector<VkImageView> swapChainImageViews;
		std::vector<VkFramebuffer> swapChainFramebuffers;

		// command
		VkCommandPool commandPool;
		VkCommandBuffer commandBuffer;
		std::vector<VkCommandBuffer> commandBuffers;



		struct SwapChainSupportDetails {
			VkSurfaceCapabilitiesKHR capabilities;
			std::vector<VkSurfaceFormatKHR> formats;
			std::vector<VkPresentModeKHR> presentModes;
		};

		VkRenderPass renderPass;
		VkPipelineLayout pipelineLayout;

		VkPipeline graphicsPipeline;


		// Drawing 
		// Sync
		VkSemaphore imageAvailableSemaphore;
		VkSemaphore renderFinishedSemaphore;
		VkFence inFlightFence;
		std::vector<VkSemaphore> imageAvailableSemaphores;
		std::vector<VkSemaphore> renderFinishedSemaphores;
		std::vector<VkFence> inFlightFences;


		// track frame
		uint32_t currentFrame = 0;

		// For GUI
		int test;

	public:
		AppBase(); // constructor
		virtual ~AppBase(); // desctructor
		
		int Run(); // 작동

		virtual bool Initialize();

	protected:

#pragma region window
		bool InitVulkan();

		bool InitWindow();
		bool ShouldClose();

		void CreateInstance();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createSwapChain();
		void createImageViews();
		void createRenderPass();

		// Drawing
		void createFramebuffers();

		// Command
		void createCommandPool();
		void createCommandBuffers();
		void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

		// Rendering and Presentation 
		void createSyncObjects();

		std::vector<const char*> getRequiredExtensions();
		int rateDeviceSuitability(VkPhysicalDevice device);


		// QueueFamilies
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

		// SwapChain
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);


		// Graphics PipeLine method
		void createSurface(); // Rendering 이미지를 관리할 객체
		void createGraphicsPipeline();
		VkShaderModule createShaderModule(const std::vector<char>& code); // wrap code in ShaderModule


		void cleanupInstance();
		void cleanupSurface();
		void cleanupSwapChain();
		void cleanupImageViews();
		void cleanupFrameBuffers();
		void cleanupCommandPool();
		void claenupSyncObjects();

		


		bool isDeviceSuitable(VkPhysicalDevice device);
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);

		
		void Update();
		void UpdateGUI();

		//mainLoop Function;
		void drawFrame();

		// App Basic Function;
		void Initialization(); // 초기화
		void mainLoop(); // 업데이트
		void CleanUp(); // 종료



		

	};

}
