# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/sachi/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/sachi/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alifuaad.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Alifuaad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alifuaad.dir/flags.make

CMakeFiles/Alifuaad.dir/main.cpp.o: CMakeFiles/Alifuaad.dir/flags.make
CMakeFiles/Alifuaad.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alifuaad.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alifuaad.dir/main.cpp.o -c /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/main.cpp

CMakeFiles/Alifuaad.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alifuaad.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/main.cpp > CMakeFiles/Alifuaad.dir/main.cpp.i

CMakeFiles/Alifuaad.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alifuaad.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/main.cpp -o CMakeFiles/Alifuaad.dir/main.cpp.s

# Object files for target Alifuaad
Alifuaad_OBJECTS = \
"CMakeFiles/Alifuaad.dir/main.cpp.o"

# External object files for target Alifuaad
Alifuaad_EXTERNAL_OBJECTS =

Alifuaad.exe: CMakeFiles/Alifuaad.dir/main.cpp.o
Alifuaad.exe: CMakeFiles/Alifuaad.dir/build.make
Alifuaad.exe: CMakeFiles/Alifuaad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Alifuaad.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Alifuaad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alifuaad.dir/build: Alifuaad.exe
.PHONY : CMakeFiles/Alifuaad.dir/build

CMakeFiles/Alifuaad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Alifuaad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Alifuaad.dir/clean

CMakeFiles/Alifuaad.dir/depend:
	cd /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug /cygdrive/c/Users/sachi/OneDrive/Desktop/Alifuaad/cmake-build-debug/CMakeFiles/Alifuaad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alifuaad.dir/depend

