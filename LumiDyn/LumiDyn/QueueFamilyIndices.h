#pragma once
#include <optional>
#include <vulkan/vulkan.h>

namespace LumiDynEngine {

    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete() const {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    // 함수 시그니처만 선언
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

} // namespace LumiDynEngine::Vulkan