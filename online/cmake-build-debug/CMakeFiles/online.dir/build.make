# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Tools\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Tools\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Tools\CLionProjects\Quests\online

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Tools\CLionProjects\Quests\online\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/online.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/online.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/online.dir/flags.make

CMakeFiles/online.dir/main.cpp.obj: CMakeFiles/online.dir/flags.make
CMakeFiles/online.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Tools\CLionProjects\Quests\online\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/online.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\online.dir\main.cpp.obj -c D:\Tools\CLionProjects\Quests\online\main.cpp

CMakeFiles/online.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/online.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Tools\CLionProjects\Quests\online\main.cpp > CMakeFiles\online.dir\main.cpp.i

CMakeFiles/online.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/online.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Tools\CLionProjects\Quests\online\main.cpp -o CMakeFiles\online.dir\main.cpp.s

# Object files for target online
online_OBJECTS = \
"CMakeFiles/online.dir/main.cpp.obj"

# External object files for target online
online_EXTERNAL_OBJECTS =

online.exe: CMakeFiles/online.dir/main.cpp.obj
online.exe: CMakeFiles/online.dir/build.make
online.exe: CMakeFiles/online.dir/linklibs.rsp
online.exe: CMakeFiles/online.dir/objects1.rsp
online.exe: CMakeFiles/online.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Tools\CLionProjects\Quests\online\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable online.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\online.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/online.dir/build: online.exe

.PHONY : CMakeFiles/online.dir/build

CMakeFiles/online.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\online.dir\cmake_clean.cmake
.PHONY : CMakeFiles/online.dir/clean

CMakeFiles/online.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Tools\CLionProjects\Quests\online D:\Tools\CLionProjects\Quests\online D:\Tools\CLionProjects\Quests\online\cmake-build-debug D:\Tools\CLionProjects\Quests\online\cmake-build-debug D:\Tools\CLionProjects\Quests\online\cmake-build-debug\CMakeFiles\online.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/online.dir/depend
