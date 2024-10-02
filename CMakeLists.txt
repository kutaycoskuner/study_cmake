# required: set required cmake version
cmake_minimum_required(VERSION 3.24)
# required: set the project name
project(tutorial)

# ----------------------------------------------------------------------------------------
#               testing simple output
# ----------------------------------------------------------------------------------------
# where cmakelists.txt lives
# message(FATAL_ERROR "This is a test  ${CMAKE_SOURCE_DIR}")

# where cmakelists.txt lives?
# message(FATAL_ERROR "This is a test2  ${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "testing ${CMAKE_BUILD_TYPE}")
# message(STATUS "${OSBitness}")
# message(FATAL_ERROR "This is a test3  ${CMAKE_HOME_SOURCE_DIR}") 


# ----------------------------------------------------------------------------------------
#               standards
# ----------------------------------------------------------------------------------------
# include(CTest) # -> testing tool included in cmake
# enable_testing()

# determine (32 / 64)
# set(InstructionSetArchitecture 32)
# if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#     set(InstructionSetArchitecture 64)
# endif()
set(InstructionSetArchitecture x64)
set(CMAKE_GENERATOR_PLATFORM ${InstructionSetArchitecture})


# optional: define which cpp standard you want to use
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Check if CMAKE_BUILD_TYPE is not set
# if(NOT CMAKE_BUILD_TYPE)
#     message(STATUS "CMAKE_BUILD_TYPE not specified. Setting default to 'Release'.")
#     set(CMAKE_BUILD_TYPE "Release")
# endif()

# ----------------------------------------------------------------------------------------
#               variable for source code
# ----------------------------------------------------------------------------------------
set(sourceCode
    "main.cpp"
)

set(outputDir 
    "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${InstructionSetArchitecture}/${CMAKE_BUILD_TYPE}"    
)

# ----------------------------------------------------------------------------------------
#               variable for source code
# ----------------------------------------------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    "${outputDir}/static_libs"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${outputDir}"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${outputDir}"
)


# add the executable (executable called first param, using the second param as source)
add_executable(${PROJECT_NAME} ${sourceCode})