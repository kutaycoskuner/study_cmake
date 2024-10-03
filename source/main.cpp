// main.cpp
#include <iostream>
#include "../headers/my_functions.h" 

int main() {
    std::cout << "Calling a function from another file..." << std::endl;
    
    // Call the function from my_functions.cpp
    printMessage();
    
    return 0;
}