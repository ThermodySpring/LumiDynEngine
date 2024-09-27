#include "EngineCore.h"

namespace LumiDynEngineCore {

    // ������: ������ �����͸� nullptr�� �ʱ�ȭ
    Window::Window() : window(nullptr) {}

    // �Ҹ���: �����찡 �����Ǿ� �ִٸ� �ı�
    Window::~Window() {
        DestroyWindow();
    }

    // ������ �ʱ�ȭ
    void Window::InitializeWindow() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // OpenGL ���ؽ�Ʈ ����
        window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
    }

    // ������ �ı�
    void Window::DestroyWindow() {
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
    }

    // ������ ���� ���� Ȯ��
    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(window);
    }

    // �̺�Ʈ ����
    void Window::PollEvents() const {
        glfwPollEvents();
    }

    // ���ø����̼� ����
    void TerminateApp() {
        glfwTerminate();
    }

    // ���ø����̼� ����
    int RunApp() {
        Window appWindow;
        appWindow.InitializeWindow();

        // ���� ����
        while (!appWindow.ShouldClose()) {
            appWindow.PollEvents();
        }

        appWindow.DestroyWindow();
        TerminateApp();

        return 0;
    }

}