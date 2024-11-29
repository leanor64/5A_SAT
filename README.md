# SatSolverTemplate
SAT solver template for a course at INSA Toulouse.

## Setup
For this course, you need a modern C++ compiler that supports C++20. I recommend using `g++` or `clang`. `MSVC` should
also work, but I haven't tested it yet. Furthermore, you need `cmake` (at least version 3.14). And finally, I recommend
that you install one of the following libraries on your system: `libdw` (`libdw-dev`), `libdwarf` (`libdwarf-dev`).
These are not necessary but help producing meaningful stacktraces which makes debugging easier. I have no idea whether
these libraries are available for Windows...

All the remaining dependencies are handled by cmake.

## Configure the Project
I recommend that you use a C++ IDE like CLion or an editor like VS-Code. Both have cmake integration making your life a
lot easier. If you like suffering and plan on developing using a basic editor, fret naught, it's not that complicated,
actually. The CMake project automatically configures all targets (the executables that you will run later) for you.
The following targets should be configured automatically:
* all_tests (runs all unit tests)
* test_basic_structures (runs only the tests for the basic structures like Variable and Literal)
* test_clause (runs only the tests for the Clause class)
* test_solver (runs only the tests for the principal member functions of the solver class)
* test_unit_propagation (runs only the tests for the unit propagation)

If you want to add other executables (e.g. a 'solve' executable that reads a problem and tries to solve it), then you
can add them in the main project file. For example, you could create `solve.cpp` file. In order to generate a build
target, you need to rerun CMake.

If you want to add a test, then you should add `test_<name of your test>.cpp` in the `Tests`-directory. Again you need
to rerun CMake for the target to be generated.

### CLion
Simply clone the project and open the folder as project with CLion. It should do everything for you. On first launch
CLion will probably ask you to create a CMake profile. Usually the proposed 'Debug' config is exactly what you want.
You can additionally create a 'Release' config by clicking on the + icon above the Debug config and it will most likely
create the appropriate release config automatically for you. When you're done just click ok. You can always add more
configs later on.

CLion should now automatically load the CMake project and configure all targets for you. You can select which target to
build on the top right of your screen. All the targets mentioned above should be available.

### VS-Code
You need to install the official Microsoft `CMake Tools` extension.
Clone the project and open the folder with VS-Code. If asked to trust the project, click on trust. VS-Code will probably
ask you to select a 'Kit' for the project. Here you select your C++-compiler. Once done, the CMake project should
automatically load.

Select the `CMake Tools` extension sidebar on the left. Depending on you VSC configuration, you should see three
tabs (usually on the left). In the 'Project Status' tab you should see six drop-down items: 
* Folder: We don't care
* Configure: Here you can select your compiler and the build configuration (Debug / Release)
* Build: We don't care
* Test: We don't care
* Debug: Here you can select a target and launch it with the debugger attached
* Launch: Here you can select a target and launch it in the console

Under the 'Project Outline' tab you should see all libraries and executables of the project. The initial targets listed
above should be visible here. You can alternatively build, launch and debug from here by right-clicking on an executable
and selecting the desired action. Or you simply use the integrated terminal and launch the executable manually (once
built, they should be in you build folder).

### Manually using CMake
If you don't want to use one of the aforementioned methods, you can manually configure the project and work with any
editor of your choice.
1. Clone the repo and change into the folder
2. Create a build folder for each build config (Debug / Release, e.g. build_dbg / build_rel)
3. To configure the project run the following command (replace <...>):
   ```
   cmake -S . -B <path to you build directory> -DCMAKE_BUILD_TYPE=<release/debug>
   ```
   CMake should run without error. Towards the end of the output you should see a list with the targets mentioned above.
   You can manually specify the compiler using the flag `-DCMAKE_CXX_COMPILER=<the compiler of your choice>`
4. To build a target run the following command
   ```
   cmake --build <path to your build folder> -t <name of the target> -j <number of processors to use>
   ```
   If the build was successful, you can launch the executable directly from the terminal. For example, if you built
   the target `test_clause` then you execute the following command:
   ```
   <name of your build folder>/Tests/test_clause
   ```
5. Whenever you add new target (e.g. the solve executable) make sure to rerun CMake (just retype the command in 3.)
