# systemc-library-installation-for-windows

## Prerequisites:

1. Working Visual Studio Code IDE:

   Install VS code (if you haven’t already):

   Go to the VS code website https://code.visualstudio.com/, download the installer, and install VS code
   
2. Download needed packages (gcc, g++ compilar, make and cmake):

   - Install MSYS2 (if you haven’t already):

   Go to the MSYS2 website https://www.msys2.org/, download the installer, and install MSYS2.
   
   - Run MSYS2 MSYS from the Start Menu to open the MSYS2 terminal.

   - Update Package Database:

   Open the MSYS2 terminal and update the package database and core system packages (to ensure everything is up-to-date) by running:
   ```
   pacman -Syu
   ```
   
   - Install essential development tools by running:
   ```
   pacman -S base-devel
   ```
   
   - Install MinGW-w64:

   To install MinGW-w64 for 64-bit, run:
   ```
   pacman -S mingw-w64-x86_64-gcc
   ```
   For 32-bit MinGW, use:
   ```
   pacman -S mingw-w64-i686-gcc
   ```
   
   - Add MinGW to PATH:

      Add the path of MinGW binaries to your system environment. The path will look something like:
      ```
      C:\msys64\mingw64\bin
      C:\msys64\mingw32\bin
      ```
      To add this, go to your System Properties > Environment Variables, find Path under System variables, and add the path above.

   - To install CMake for 64-bit, run:
   ```
   pacman -S mingw-w64-x86_64-cmake
   ```
   For 32-bit CMake (you may use this even if your machine 64-bit), use:
   ```
   pacman -S mingw-w64-i686-cmake
   ```
   
   - Install make:
   ```
   pacman -S mingw-w64-x86_64-make
   ```
3. Git Windows:

   Install Git (if you haven’t already):

   Go to the Git website https://git-scm.com/, download the installer, and install Git
   

## The installation steps involved:

1. Download SystemC Source:
   - Open the Git terminal from the Start Menu and clone the SystemC repo in C:\ Folder, use:
   ```
   git clone https://github.com/accellera-official/systemc
   ```
   then delete the .git file.

   - From the Accellera SystemC website https://accellera.org/ download the latest SystemC package (you may need to create an account).
   
   Extract the Source:

   Unzip the downloaded SystemC file into a directory, e.g., C:\SystemC.

2. CMake Configuration with SystemC:

   - Run MSYS2 MINGW64 from the Start Menu to open the MINGW terminal and navigate to the SystemC directory.
   ```
   cd systemc
   ```
   
   - Create a build directory and navigate into it
   ```
   mkdir build
   cd build
   ```
   
   - CMake Configuration
   ```
   cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_EXTENSIONS=OFF -DCMAKE_INSTALL_PREFIX="C:\systemc\build" ..
   ```
   you can specify the installation path using DCMAKE_INSTALL_PREFIX=%PATH%
   
4. Build SystemC with CMake:

   - Building SystemC Library:
   ```
   cmake --build . --config Debug
   ```
   
   - Running Sanity tests to validate the built library is functional(optional)
   ```
   cmake --build . --config Debug --target check-examples
   ```
   This should run all the examples available with SystemC release and all of them should pass without any failures.

5. SystemC library installation:

   - Run the following command to compile and install SystemC:
   ```
   cmake --build . --config Debug --target install
   ```
   This will compile the library and install it in C:\SystemC\install.

6. Set Up Environment Variables for Windows:

   - **SystemC Home Directory:** Open Environment Variables in Windows and add a new user variable named SYSTEMC_HOME with the path to your SystemC installation (e.g., C:\systemc).

   - **Include and Library Paths:** Add SYSTEMC_HOME\include to the INCLUDE path and SYSTEMC_HOME\lib to the LIB path.

7. Compile a SystemC Project:

   To compile a simple SystemC project on Windows, open the MSYS2 MinGW terminal and use the following command:
   ```
   g++ -o my_systemc_project my_systemc_project.cpp -I$SYSTEMC_HOME/include -L$SYSTEMC_HOME/lib -lsystemc -lm
   ```
   if you have not set up SYSTEMC_HOME as environmental variables use the abslute paths for INCLUDE path (e.g., C:\systemc\build\include) and LIB path (e.g., C:\systemc\build\lib)

8. Run a Test Program:

   - Verify the installation and run the attached file my_systemc_project.cpp using CMD by running the above command.
   - Expected Output
     When you run this program, you should see:
  ```
   Hello, SystemC!
  ```

9. Run any systemc project using run botton in VS code:

   If the manual command works, configure a build task in .vsCode file:
   - Edit tasks.json as follows:
   ```
   {
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\msys64\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-I", "C:/systemc/build/include",           // Include path to SystemC headers
                "-L", "C:/systemc/build/lib",               // Library path for SystemC
                "-lsystemc",                                // Link SystemC library
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
   }
   ```
   
   - Edit c_cpp_properties.json as follows:
   ```
   {
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/systemc/build/include"                   // SystemC include path
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:/msys64/mingw64/bin/g++.exe",  // Path to your MinGW g++ compiler
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
   }
   ```
   
Hope this helps.

Let us know in case you face any issues setting it up.
