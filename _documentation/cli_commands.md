Remove-Item -Path "C:\Users\kutay\OneDrive\Documents\GitHub\study_cmake\bin" -Recurse -Force
    - removing bin directory

Remove-Item -Path "C:\Users\kutay\OneDrive\Documents\GitHub\study_cmake\build" -Recurse -Force
    - removing build directory

./_GenerateBuildProject.bat
    - run genrate build project script

./_GenerateBinaries.bat
    - run generate binaries

./build/tutorial.sln
    - run solution

./bin/Windows/x64/Debug/tutorial.exe
    - run binary