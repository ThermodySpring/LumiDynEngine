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
        // ������
        Window();

        // �Ҹ���
        ~Window();

        // ������ �ʱ�ȭ
        void InitializeWindow();

        // ������ �ı�
        void DestroyWindow();

        // ������ ���� ���� Ȯ��
        bool ShouldClose() const;

        // �̺�Ʈ ����
        void PollEvents() const;
    };

    // ���ø����̼� ���� �Լ�
    void TerminateApp();

    // ���ø����̼� ���� �Լ�
    int RunApp();

}

#endif // ENGINECORE_H