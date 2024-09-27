#ifndef ENGINECORE_H
#define ENGINECORE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

namespace LumiDynEngineCore {

    class Window {
    private:
        GLFWwindow* window;

    public:
        // 생성자
        Window();

        // 소멸자
        ~Window();

        // 윈도우 초기화
        void InitializeWindow();

        // 윈도우 파괴
        void DestroyWindow();

        // 윈도우 종료 여부 확인
        bool ShouldClose() const;

        // 이벤트 폴링
        void PollEvents() const;
    };

    // 애플리케이션 종료 함수
    void TerminateApp();

    // 애플리케이션 실행 함수
    int RunApp();

}

#endif // ENGINECORE_H