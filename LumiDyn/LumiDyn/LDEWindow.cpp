#include "LDEWindow.h"

namespace LumiDynEngine {

    // Constructor --> initialzie (width, height, name) 
    LDEWindow::LDEWindow(int w, int h, std::string name)
        : width{ w }, height{ h }, windowName{ name } {
        InitializeWindow();
    };

    LDEWindow::~LDEWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    // 윈도우 초기화
    void LDEWindow::InitializeWindow() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // OpenGL 컨텍스트 생성 X 
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // 창 크기 변경 비활성
        
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        // 마지막 2개 인수는 OpenGL 사용과 연관 되어 있으므로 nullptr 할당해 사용 X
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
    }

    bool LDEWindow::ShouldClose() {
        return glfwWindowShouldClose(window); // 사용자가 창을 닫기 원하는 지에 대한 쿼리
    }

   

}