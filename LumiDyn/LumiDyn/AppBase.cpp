#include "AppBase.h"

namespace LumiDynEngine {

	int AppBase::Run() {

		while (!m_window.ShouldClose()) {
			glfwPollEvents();
		}
		return 1;
	};
}