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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/msc_frank17.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/msc_frank17.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/msc_frank17.dir/flags.make

CMakeFiles/msc_frank17.dir/main.cpp.o: CMakeFiles/msc_frank17.dir/flags.make
CMakeFiles/msc_frank17.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/msc_frank17.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/msc_frank17.dir/main.cpp.o -c /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/main.cpp

CMakeFiles/msc_frank17.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/msc_frank17.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/main.cpp > CMakeFiles/msc_frank17.dir/main.cpp.i

CMakeFiles/msc_frank17.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/msc_frank17.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/main.cpp -o CMakeFiles/msc_frank17.dir/main.cpp.s

# Object files for target msc_frank17
msc_frank17_OBJECTS = \
"CMakeFiles/msc_frank17.dir/main.cpp.o"

# External object files for target msc_frank17
msc_frank17_EXTERNAL_OBJECTS =

msc_frank17.exe: CMakeFiles/msc_frank17.dir/main.cpp.o
msc_frank17.exe: CMakeFiles/msc_frank17.dir/build.make
msc_frank17.exe: CMakeFiles/msc_frank17.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable msc_frank17.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msc_frank17.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/msc_frank17.dir/build: msc_frank17.exe
.PHONY : CMakeFiles/msc_frank17.dir/build

CMakeFiles/msc_frank17.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/msc_frank17.dir/cmake_clean.cmake
.PHONY : CMakeFiles/msc_frank17.dir/clean

CMakeFiles/msc_frank17.dir/depend:
	cd /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17 /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17 /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug /cygdrive/c/Users/sachi/OneDrive/Desktop/msc_frank17/cmake-build-debug/CMakeFiles/msc_frank17.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/msc_frank17.dir/depend

