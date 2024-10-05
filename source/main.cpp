// main.cpp
#include <iostream>
#include "../headers/my_functions.h"
#include "../libs/header_hello_1.0.0/hello.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>  // Standard OpenGL functions
#include <iostream>

// Callback function for GLFW errors
void error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

int main()
{

       // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Set the error callback
    glfwSetErrorCallback(error_callback);

    // Specify OpenGL version (if needed), e.g., 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Test Window", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen with a color (RGBA)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
    
    std::cout << "Calling a function from another file..." << std::endl;

    // Call the function from my_functions.cpp
    printMessage();

    hello::sayHello();

    // Create an instance of the Importer class
    Assimp::Importer importer;

    // Load the STL model (or any other format Assimp supports)
    const aiScene *scene = importer.ReadFile(DATA_DIR + std::string("test.stl"),
                                            aiProcess_Triangulate | aiProcess_FlipUVs);

    // Check if the model was loaded successfully
    if (!scene)
    {
        std::cerr << "Assimp import failed: " << importer.GetErrorString() << std::endl;
        return -1;
    }

    std::cout << "Assimp import succeeded!" << std::endl;
    std::cout << "Model has " << scene->mNumMeshes << " mesh(es)." << std::endl;

    return 0;
}