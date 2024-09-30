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

    // ������ �ʱ�ȭ
    void LDEWindow::InitializeWindow() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // OpenGL ���ؽ�Ʈ ���� X 
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // â ũ�� ���� ��Ȱ��
        
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        // ������ 2�� �μ��� OpenGL ���� ���� �Ǿ� �����Ƿ� nullptr �Ҵ��� ��� X
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
    }

    bool LDEWindow::ShouldClose() {
        return glfwWindowShouldClose(window); // ����ڰ� â�� �ݱ� ���ϴ� ���� ���� ����
    }

   

}