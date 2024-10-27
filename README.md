# systemc-library-installation-for-windows

## Prerequisites:

1. Working Visual Studio Code IDE

   Install VS code (if you haven’t already):

   Go to the VS code website https://code.visualstudio.com/, download the installer, and install VS code
   
2. MSYS2 MINGW terminal and needed packages (gcc, g++ compilar and cmake)

   - Install MSYS2 (if you haven’t already):

   Go to the MSYS2 website https://www.msys2.org/, download the installer, and install MSYS2.
   
   - Run MSYS2 MSYS from the Start Menu to open the MSYS2 terminal.

   - Update Package Database:

   Open the MSYS2 terminal and update the package database and core system packages by running:
   ```
   pacman -Syu
   ```
   After this, close the terminal and reopen it, then run the following command to ensure everything is up-to-date:
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
      ```
      To add this, go to your System Properties > Environment Variables, find Path under System variables, and add the path above.

   - Install CMake:
   ```
   pacman -S mingw-w64-x86_64-cmake
   ```
   - Install make:
   ```
   pacman -S mingw-w64-x86_64-make
   ```
   
