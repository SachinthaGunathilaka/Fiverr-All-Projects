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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Whatsapp_FIverr.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Whatsapp_FIverr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Whatsapp_FIverr.dir/flags.make

CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o: CMakeFiles/Whatsapp_FIverr.dir/flags.make
CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o: ../Task5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o -c "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/Task5.cpp"

CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/Task5.cpp" > CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.i

CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/Task5.cpp" -o CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.s

# Object files for target Whatsapp_FIverr
Whatsapp_FIverr_OBJECTS = \
"CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o"

# External object files for target Whatsapp_FIverr
Whatsapp_FIverr_EXTERNAL_OBJECTS =

Whatsapp_FIverr.exe: CMakeFiles/Whatsapp_FIverr.dir/Task5.cpp.o
Whatsapp_FIverr.exe: CMakeFiles/Whatsapp_FIverr.dir/build.make
Whatsapp_FIverr.exe: CMakeFiles/Whatsapp_FIverr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Whatsapp_FIverr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Whatsapp_FIverr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Whatsapp_FIverr.dir/build: Whatsapp_FIverr.exe
.PHONY : CMakeFiles/Whatsapp_FIverr.dir/build

CMakeFiles/Whatsapp_FIverr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Whatsapp_FIverr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Whatsapp_FIverr.dir/clean

CMakeFiles/Whatsapp_FIverr.dir/depend:
	cd "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr" "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr" "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug" "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug" "/cygdrive/c/Users/sachi/OneDrive/Desktop/Whatsapp FIverr/cmake-build-debug/CMakeFiles/Whatsapp_FIverr.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Whatsapp_FIverr.dir/depend

