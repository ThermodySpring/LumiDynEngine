cmake_minimum_required(VERSION 3.14)
project(MyVulkanApp)

set(CMAKE_CXX_STANDARD 17)

# Vulkan 찾기
find_package(Vulkan REQUIRED)
if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan SDK not found!")
endif()

# FetchContent 모듈 사용
include(FetchContent)

# GLFW 다운로드 및 빌드
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8  # 원하는 버전으로 설정
)

FetchContent_MakeAvailable(glfw)

# Dear ImGui 다운로드 및 빌드
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        v1.89.2  # 원하는 버전으로 설정
)

FetchContent_MakeAvailable(imgui)

# Dear ImGui 백엔드 추가
add_library(imgui_impl_vulkan STATIC
    ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp
)
target_include_directories(imgui_impl_vulkan PUBLIC ${imgui_SOURCE_DIR})

add_library(imgui_impl_glfw STATIC
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
)
target_include_directories(imgui_impl_glfw PUBLIC ${imgui_SOURCE_DIR})

# Dear ImGui 소스 추가
add_library(imgui
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
)

target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# 소스 파일 추가
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(MyVulkanApp ${SOURCES})

# Include 디렉토리 설정
target_include_directories(MyVulkanApp PRIVATE
    ${Vulkan_INCLUDE_DIRS}
    ${glfw_SOURCE_DIR}/include
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
)

# 링크 라이브러리 설정
target_link_libraries(MyVulkanApp PRIVATE
    Vulkan::Vulkan
    glfw
    imgui
    imgui_impl_vulkan
    imgui_impl_glfw
)