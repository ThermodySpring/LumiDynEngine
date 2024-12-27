#pragma once

#ifndef INSTANCE_MANAGER_H
#define INSTANCE_MANAGER_H

#include <vulkan/vulkan.h>
#include <vector>
#include <string>

namespace LumiDynEngine {

    namespace Vulkan {

        class InstanceManager {
        public:
            void createInstance();
            std::vector<const char*> getRequiredExtensions();

            VkInstance getInstance() const;

        private:
            VkInstance instance;
            VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
            // 추가적인 멤버 변수들
        };
    }
} //namespace LumiDynEngine

#endif // INSTANCE_MANAGER_H
