# Set required CMake version
cmake_minimum_required(VERSION 3.24)

# Set the project name
project(tutorial)

# ----------------------------------------------------------------------------------------
#               Standards and Configurations
# ----------------------------------------------------------------------------------------

# Optional: Define the C++ standard you want to use
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the architecture
set(InstructionSetArchitecture x64)
set(CMAKE_GENERATOR_PLATFORM ${InstructionSetArchitecture})

# Set startup project to project other than CMake builds (for Visual Studio)
set_property(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
)

# Set default build type if not specified (optional)
# if(NOT CMAKE_BUILD_TYPE)
#     message(STATUS "CMAKE_BUILD_TYPE not specified. Setting default to 'Release'.")
#     set(CMAKE_BUILD_TYPE "Release")
# endif()

# ----------------------------------------------------------------------------------------
#               Source Code and Output Directories
# ----------------------------------------------------------------------------------------
# Define the source code files
set(sourceCode
    "source/main.cpp"
    "source/my_functions.cpp"  # Add the additional source file here
)

# Define the output directory based on system name, architecture, and build type
set(outputDir 
    "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${InstructionSetArchitecture}/${CMAKE_BUILD_TYPE}"    
)

# Specify where to output archive (static libs), libraries, and executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    "${outputDir}/static_libs"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${outputDir}"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${outputDir}"
)


# ----------------------------------------------------------------------------------------
#               Adding Libraries
# ----------------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/libs/header_hello_1.0.0")
add_library( # MODULE, STATIC, SHARED (DYNAMIC)
    "hello" STATIC
    "libs/header_hello_1.0.0/hello.cpp"
)

# submodules
add_subdirectory("${CMAKE_SOURCE_DIR}/libs/assimp") 

# ----------------------------------------------------------------------------------------
#               Include Directories and Executable
# ----------------------------------------------------------------------------------------
# Add the headers directory so the compiler can find header files
include_directories("${CMAKE_SOURCE_DIR}/headers")

# Add the executable, linking the project name with the source files
add_executable(${PROJECT_NAME} ${sourceCode})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/assimp/include)
# ----------------------------------------------------------------------------------------
#               Linking Libraries
# ----------------------------------------------------------------------------------------
# linking library should come after generation of executable?
target_link_libraries(${PROJECT_NAME} PRIVATE assimp)
target_link_libraries(${PROJECT_NAME} PRIVATE hello)