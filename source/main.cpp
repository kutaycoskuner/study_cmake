// main.cpp
#include <iostream>
#include "../headers/my_functions.h" 
#include "../libs/header_hello_1.0.0/hello.hpp"

int main() {
    std::cout << "Calling a function from another file..." << std::endl;
    
    // Call the function from my_functions.cpp
    printMessage();

    hello::sayHello();
    
    return 0;
}