# Notebook

# Installation and Use
- prerequisites
- install
- build
- run deployment
- run release

# Links
- link
    - url

# Keywords

# Structure
root/
│
├── CMakeLists.txt
├── source/
│   ├── main.cpp
│   └── my_functions.cpp
├── headers/
    └── my_functions.h

# Blackboard
- <post build script>
    - datayi .exe nin yanina tasi

- <develpment ve packaging baska ortamlar oldugu icin veriye erisim ulasamayabiliyor>
    - 

- <github submodule>
    - gith submodule add <liknk>
        - git submodule add https://github.com/glfw/glfw.git
        - warning: in the working copy of '.gitmodules', LF will be replaced by CRLF the next time Git 
        - readonly yapiyor git init
        touches it
    - to add submodules with your git pull
        - git config submodule.recurse true
        - git submodule update --init
    - updating submodule
        - baska branch e checkout yapip commitliyorsun.
        - root commit e donup update ediyorsun.
    - how to change submodule folder name
        - rename folder ren old new
        - go to .gitmodules change name and path

- <libraries>
    - static 
    - dynamic (shared)
    - header only
    - precompiled
    - obj libs
    - frameworks
    - plugin libs
    - runtime libs

    - sub modules

    - structure
        - naming convention <type>_<name-stuff>_<version.subversion>
                            assimp-5.2.3
        - build
        - include
        - src

- <what is build system>
    - https://www.youtube.com/watch?v=_BWU5mWqVA4
    - a set of tools and processses that can track how you want to compile and link your code
    - describe project structure and dependencies   
    - make, ninja, msbuild, cmake (meta-system)
    - cmake allows
        - handling dependencies
        - supporting cross-platform development

- <legacy>
    - cmake tools extension (vsc)
    - cpp extension (vsc)
    - install cmake
        - cmake --version
    - cpp compiler
        - gcc --version
        - make calismiyorsa
            - mingw-get -> paket manager i aciyor
    - debugger

    # Steps
    1. have your source code
        - main.cpp
            - create a simple cpp file
            gcc -o hello main.cpp 
            ->      compile to executable
            ./hello 
            ->      run the code

    2. check cmake installed
        cmake --version
        ->      ensure cmake is installed

    3. create CMakeLists.txt file


    4. make a build directory to avoid cluster
    mkdir build
    cd build
    cmake ..            -> generates files to build

    5. sln ac / build
    startup projesi sec
    - alternatif
    cmake --build . --config Release


- central configuration file 
- CMake Presets / Kits and Variants
- preset for windows / mac / linux
- cmake . && make && ./hello
- cmake .
- mingw32-make
- cmake -G "MinGW Makefiles" .

- cmake .. -G

- cmake -G "Visual Studio 17 2022" -A x64 ..
- cmake -S .. -B build -G "MinGW Makefiles" -DCMAKE_C_COMPILER="C:\MinGW\bin\gcc.exe" -DCMAKE_CXX_COMPILER="C:/Path/To/MinGW/bin/g++.exe"


# How to

# Problems
- <problem>

