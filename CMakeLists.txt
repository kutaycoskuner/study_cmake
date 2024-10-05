# Set required CMake version
cmake_minimum_required(VERSION 3.24)

# Set the project name
project(tutorial)

# multiprocessor compile
add_compile_options(/MP)

# ----------------------------------------------------------------------------------------
#               Standards and Configurations
# ----------------------------------------------------------------------------------------

# Optional: Define the C++ standard you want to use
set(CMAKE_CXX_STANDARD 20)
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
#               Main Directories
# ----------------------------------------------------------------------------------------
# Define the source code files
set(sourceDir
    "source"
)

set(dataDir
    "${CMAKE_SOURCE_DIR}/data/" 
) 

# Define the output directory based on system name, architecture, and build type
set(outputDir 
"${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${InstructionSetArchitecture}/${CMAKE_BUILD_TYPE}"    
)


# ----------------------------------------------------------------------------------------
#               Main Files
# ----------------------------------------------------------------------------------------
set(sourceCode
    "${sourceDir}/main.cpp"
    "${sourceDir}/my_functions.cpp"  # Add the additional source file here
)

set(dataFiles
    "${dataDir}/test.stl"
)


# ----------------------------------------------------------------------------------------
#               CMake Environment Variables
# ----------------------------------------------------------------------------------------
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
#               Adding Required Packages (OpenGL, GLFW, GLEW, etc.)
# ----------------------------------------------------------------------------------------
# Find OpenGL
find_package(OpenGL REQUIRED)

# Optional: Find other libraries (GLFW, GLEW, etc.)
# For example, to add GLFW, you can use:
# find_package(GLFW3 REQUIRED)


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
add_subdirectory("${CMAKE_SOURCE_DIR}/libs/glfw") 

# ----------------------------------------------------------------------------------------
#               Include Directories and Executable
# ----------------------------------------------------------------------------------------
# Add the headers directory so the compiler can find header files
include_directories("${CMAKE_SOURCE_DIR}/headers")

# Add the executable, linking the project name with the source files
add_executable(${PROJECT_NAME} ${sourceCode})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/assimp/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/glfw/include)

# this definition could be used in code
add_compile_definitions(DATA_DIR="${dataDir}")
# ----------------------------------------------------------------------------------------
#               Linking Libraries
# ----------------------------------------------------------------------------------------
# Link the OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)


# linking library should come after generation of executable?
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE assimp)
target_link_libraries(${PROJECT_NAME} PRIVATE hello)