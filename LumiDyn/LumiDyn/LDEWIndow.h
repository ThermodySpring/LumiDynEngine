#pragma once

// What is GLFW --> Graphics Library FrameWork
// How to draw Graphic : (1) window, (2)context, (3)handler
// OS마다 (1) (2) (3)을 만드는 방법이 다름 --> 이에 관한 추상화된 방법을 제공하는 OpenGL
// GLFW는 window 생성, context 생성 관리, 입력 처리 등을 받기 위한 플랫폼에 맞는 기능을 제공(멀티 플랫폼)

#define GLFW_INCLUDE_VULKAN // glfw가 Vulkan header를 포함하기 위해 정의 (GLFW header include 이전에 define)
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

