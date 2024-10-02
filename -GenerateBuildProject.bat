@echo off
:: echo off is preventing to print all lines of code 

setlocal enabledelayedexpansion
:: What is Delayed Expansion?
:: In a batch file, by default, variables are evaluated at the time a line of code is parsed, not when the code is executed. This can cause issues in loops or conditionals where the value of a variable may change during execution, but the batch interpreter doesn't recognize the updated value because it uses the initial value from the time the line was parsed.

:: ---------------------------------------------------------------------------------------
::              global contants
:: ---------------------------------------------------------------------------------------
set LAUNCH_VS=1
set SOLUTION_DIRECTORY=build

:: TODO Parameter scan



:: ---------------------------------------------------------------------------------------
::              main
:: ---------------------------------------------------------------------------------------
echo.
:: echo. -> new line
echo Checking program prerequisites...


:: check if cmake is installed
cmake --version > nul 2>&1
if !errorlevel! NEQ 0 (
    echo [] cannot find path to cmake. Please install cmake.
    exit /b -1
) else (
    echo []   CMake            - Ready.
)

:: Check if submodule is initialized to avoid CMake file not found errors
call :CheckAndInitializeSubmodules

:: Generate build directory
if not exist !SOLUTION_DIRECTORY! (
    echo [] Creating directory !SOLUTION_DIRECTORY!...
    mkdir !SOLUTION_DIRECTORY!
)

:: TODO Run cmake
cd !SOLUTION_DIRECTORY!

echo.
echo generataing solution files.

cmake ..


::if !LAUNCH_VS! EQU 1 (
::    start %SOLUTION_FILE%
::)

if !errorlevel! EQU 0 (
    echo [] Success!
) else (
    echo.
    echo [] Error with CMake. No solution files generated.
    echo. 
    pause
)

:: generate binaries
cd ..
call -GenerateBinaries.bat


exit /b 0

:: ---------------------------------------------------------------------------------------
::              functions
:: ---------------------------------------------------------------------------------------
:CheckAndInitializeSubModules
:: TODO write this function if necessary
echo.
echo checking and initializing submodules.
exit /b 0
