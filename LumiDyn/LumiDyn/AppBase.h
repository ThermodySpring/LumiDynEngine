#pragma once

#include "LDEWindow.h"

namespace LumiDynEngine {
	
	class AppBase {
	private:
		LDEWindow m_window{ WIDTH, HEIGHT, "Base Window"};

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		int Run();



	};

}
