#include "AppBase.h"

namespace LumiDynEngine {


	bool AppBase::InitVulkan() {
		CreateInstance();

		return -1;
	}

	void AppBase::CreateInstance() {
		
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Test";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "LumiDynEngine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;



		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;


		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		std::cout << "ExtensionCount: " << glfwExtensionCount; 

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;



		createInfo.enabledLayerCount = 0;

		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
		if (result != VK_SUCCESS) {
			std::cout << "Failed to create VkInstance!" << std::endl;
		}
	}

	void AppBase::cleanupInstance() {
		vkDestroyInstance(instance, nullptr);
	}


	int AppBase::Run() {
		InitVulkan();

		while (!m_window.ShouldClose()) {
			glfwPollEvents();
		}
		return 1;
	};
}