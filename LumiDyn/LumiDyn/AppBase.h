#pragma once

#include "LDEWindow.h"


namespace LumiDynEngine {
	
	class AppBase {
	private:
		LDEWindow m_window{ WIDTH, HEIGHT, "Base Window" };
		VkInstance instance;

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		int Run();

	protected:
		bool InitVulkan();
		void MainLoop();
		void CleanUp();
		void CreateInstance();
		void cleanupInstance();
		


	};

}
