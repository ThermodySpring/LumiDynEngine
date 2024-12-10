#include "AppBase.h"

namespace LumiDynEngine {

	// Main Window 생성 관련
	// 윈도우 초기화
	// App Constructor
	AppBase::AppBase() : m_screenWidth(1280), m_screenHeight(720), 
	 windowName("Test"), m_window(0) {
	
	};

	// App Destructor
	AppBase::~AppBase() {

		// 앱이 작동을 중지하면 창도 닫아야 하므로
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	bool AppBase::Initialize() {
		if (!InitWindow()) return false;

		if (!InitVulkan()) return false;


		return true;
	}


	void AppBase::createSurface() {
		if (glfwCreateWindowSurface(instance, m_window, nullptr, &surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface!");
		}
	}

	bool AppBase::InitWindow() {
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // OpenGL 컨텍스트 생성 X 
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // 창 크기 변경 비활성

		m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, windowName.c_str(), nullptr, nullptr);
		// 마지막 2개 인수는 OpenGL 사용과 연관 되어 있으므로 nullptr 할당해 사용 X
		if (!m_window) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();

			return false;
		}

		return true;
	}

	bool AppBase::ShouldClose() {
		return glfwWindowShouldClose(m_window); // 사용자가 창을 닫기 원하는 지에 대한 쿼리
	}



	// vulkan Instance 생성 관련
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
	void AppBase::createGraphicsPipeline() {
		auto vertShaderCode = FileUtils::readFile("base/vert.spv");
		auto fragShaderCode = FileUtils::readFile("base/frag.spv");
	};

	void AppBase::cleanupInstance() {
		vkDestroyInstance(instance, nullptr);
	}

	void AppBase::pickPhysicalDevice() {
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

		//Listing the graphics cards 
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
		if (deviceCount == 0) {
			throw std::runtime_error("failed to find GPUs with Vulkan support!");
		}
		
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

		for (const auto& device : devices) {
			if (isDeviceSuitable(device)) {
				physicalDevice = device;
				break;
			}
		}

		if (physicalDevice == VK_NULL_HANDLE) {
			throw std::runtime_error("failed to find a suitable GPU!");
		}

	}

	bool AppBase::isDeviceSuitable(VkPhysicalDevice device) {
		return true;
	}


	int AppBase::Run() {

		while (!ShouldClose()) {
			glfwPollEvents();
		}

		
		return 1;
	};


	// cleanUp
	void AppBase::cleanUpSurface() {
		vkDestroySurfaceKHR(instance, surface, nullptr);
	}

}