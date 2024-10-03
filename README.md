<h1 align="center">
    CMake Study Repository
</h1>

This repository is dedicated to studying and experimenting with CMake, a powerful cross-platform build system generator.

<p align="center">
    <img alt="GCC Compiler" src="https://img.shields.io/badge/GCC-6.3.0-blue?logo=gcc&logoColor=white" />
    <img alt="CMake" src="https://img.shields.io/badge/CMake-3.24.1-blue?logo=cmake&logoColor=white" />
    <img alt="Start Date" src="https://img.shields.io/badge/project_start-02_Oct_2024-blue" />
    <img alt="Last Update" src="https://img.shields.io/github/last-commit/kutaycoskuner/study_cmake" />
</p>


# Installation and Running
## Prerequisites

Before you can set up and run this project, ensure you have the following installed:

- [CMake](https://cmake.org/download/) (version 3.24.1 or higher)
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) or higher (with the C++ development workload installed)
- [Windows 10 SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/) (version 10.0.19041.0 or higher)

## Installation

To install and set up the repository locally, follow these steps:

1. **Clone the repository**: Open your terminal or Git Bash, and run:
   ```bash
   git clone https://github.com/kutaycoskuner/study_cmake.git
   cd study_cmake

### Automated generation through .bat script
2. Activate `-GenerateBuildProject.bat`  
    `:root:`
    ```bash
    ./-GenerateBuildProject.bat
    ```

### (Alternative) Manual build with cmake
2. **Create and Navigate to Build Directory**
    ```bash
    mkdir build
    cd build
    ```

3. **When in build directory Run cmake to refer root folder**
    ```bash
    cmake ..
    ```

## Run
1. Open solution (.sln) file in build  
    `:root:/build`
    ```
    ./tutorial.sln
    ```