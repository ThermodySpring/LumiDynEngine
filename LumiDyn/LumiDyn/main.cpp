#include "AppBase.h"

#include <iostream>
#include <stdexcept>

int main() {
	LumiDynEngine::AppBase app;
	if (!app.Initialize()) return -1;

	if (!app.Run()) {
		std::cout << "Application Run failed." << std::endl;
	}

	return EXIT_SUCCESS;
}