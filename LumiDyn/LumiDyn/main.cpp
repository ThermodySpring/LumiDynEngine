#include "AppBase.h"

#include <iostream>
#include <stdexcept>

int main() {
	LumiDynEngine::AppBase app{};

	if (!app.Run()) {
		std::cout << "Application Run failed." << std::endl;
	}


}