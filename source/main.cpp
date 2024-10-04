// main.cpp
#include <iostream>
#include "../headers/my_functions.h"
#include "../libs/header_hello_1.0.0/hello.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int main()
{
    std::cout << "Calling a function from another file..." << std::endl;

    // Call the function from my_functions.cpp
    printMessage();

    hello::sayHello();

    // Create an instance of the Importer class
    Assimp::Importer importer;

    // Load the STL model (or any other format Assimp supports)
    const aiScene *scene = importer.ReadFile("data/test.stl",
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