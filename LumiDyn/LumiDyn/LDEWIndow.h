#pragma once

// What is GLFW --> Graphics Library FrameWork
// How to draw Graphic : (1) window, (2)context, (3)handler
// OS���� (1) (2) (3)�� ����� ����� �ٸ� --> �̿� ���� �߻�ȭ�� ����� �����ϴ� OpenGL
// GLFW�� window ����, context ���� ����, �Է� ó�� ���� �ޱ� ���� �÷����� �´� ����� ����(��Ƽ �÷���)

#define GLFW_INCLUDE_VULKAN // glfw�� Vulkan header�� �����ϱ� ���� ���� (GLFW header include ������ define)
#include <GLFW/glfw3.h>
#include <string>

#include <iostream>

namespace LumiDynEngine {

    class LDEWindow {
    private:
        const int width;
        const int height;

        std::string windowName;
        GLFWwindow* window;

        void InitializeWindow();

    public:
        // Constructor
        LDEWindow(int w, int h, std::string name);
        
        // Destructor
        ~LDEWindow();

        bool ShouldClose();
       
    };


}

