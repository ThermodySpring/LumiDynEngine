#include "EngineCore.h"

namespace LumiDynEngineCore {

    // 생성자: 윈도우 포인터를 nullptr로 초기화
    Window::Window() : window(nullptr) {}

    // 소멸자: 윈도우가 생성되어 있다면 파괴
    Window::~Window() {
        DestroyWindow();
    }

    // 윈도우 초기화
    void Window::InitializeWindow() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // OpenGL 컨텍스트 비사용
        window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
    }

    // 윈도우 파괴
    void Window::DestroyWindow() {
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
    }

    // 윈도우 종료 여부 확인
    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(window);
    }

    // 이벤트 폴링
    void Window::PollEvents() const {
        glfwPollEvents();
    }

    // 애플리케이션 종료
    void TerminateApp() {
        glfwTerminate();
    }

    // 애플리케이션 실행
    int RunApp() {
        Window appWindow;
        appWindow.InitializeWindow();

        // 메인 루프
        while (!appWindow.ShouldClose()) {
            appWindow.PollEvents();
        }

        appWindow.DestroyWindow();
        TerminateApp();

        return 0;
    }

}