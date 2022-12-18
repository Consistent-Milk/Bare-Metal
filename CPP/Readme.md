- Added boost and fmt through MSYS2 in mingw64 environment. This changes the way how fmt has been used up to now.

-> Compiled using --std=gnu++23 (Important because many methods are not implemented in the default selection,
which is usually --std=gnu++17)

-> STL = Standard Library, TPL = Third-party Library, CH = Custom Header

-> Compiling using external libraries may become a bit complex on VSCode if done directly through command shell.

## Three Processes for Compilation and Running:

Process 1:

An example command of using BigNumber to compile a program file is as follows(This is only for 3_05.cpp program):

// Open this file in integrated terminal then run the below command to use the BigNumber Library and compile this program.

// g++ --std=gnu++23 -I ../libraries/BigNumber/src 3_05.cpp ../libraries/BigNumber/src/bignumber.cpp -o 3_05.exe (Windows)

// g++ --std=gnu++23 -I ../libraries/BigNumber/src 3_05.cpp ../libraries/BigNumber/src/bignumber.cpp -o 3_05 (Linux)

// Enter to run: 3_05.exe (Windows)

// Enter to run: ./3_05 (Linux)

Process 2:

-> The manual compilation can be bypassed by configuring the tasks.json file generated in the root .vscode folder. This will allow compiling using the run button on the top right corner. An example for windows is given in example_tasks.json file.

Process 3:

Using powershell scripts(.ps1) or bash scripts(.sh).

-> For 'actual' projects using a proper build system from Visual Studio, CMAKE or MESON may be more appropriate.

-> Decided to not use 'using namespace std' as a personal practice, which may make the programs look more verbose than necessary. In my case, using std:: let's me know without thinking where some name is coming from. This might be more useful when working with several namespaces.

Note to self: Consider using CMAKE or MESON?
