//
//  main.cpp
//  VulkanTesting
//
//  Created by John Katsikis on 20/08/2025.
//

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 1280; //specifies horizontal resolution
const uint32_t HEIGHT = 720; //specifies vertical resolution
//decided to specify my window as 720p

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;
    
    void initWindow() {
        glfwInit();
    
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //initializes the GLFW library
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //locks the window into its current resolution
        
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); //creates the window
    }
    
    void initVulkan() {

    }

    void mainLoop() {
        while(!glfwWindowShouldClose(window)){ //keeps the window running until its forced to close, either by user input or by error
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);
        
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
