# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build

# Include any dependencies generated for this target.
include CMakeFiles/DynArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DynArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DynArray.dir/flags.make

CMakeFiles/DynArray.dir/main.cpp.o: CMakeFiles/DynArray.dir/flags.make
CMakeFiles/DynArray.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DynArray.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DynArray.dir/main.cpp.o -c /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/main.cpp

CMakeFiles/DynArray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DynArray.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/main.cpp > CMakeFiles/DynArray.dir/main.cpp.i

CMakeFiles/DynArray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DynArray.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/main.cpp -o CMakeFiles/DynArray.dir/main.cpp.s

# Object files for target DynArray
DynArray_OBJECTS = \
"CMakeFiles/DynArray.dir/main.cpp.o"

# External object files for target DynArray
DynArray_EXTERNAL_OBJECTS =

DynArray: CMakeFiles/DynArray.dir/main.cpp.o
DynArray: CMakeFiles/DynArray.dir/build.make
DynArray: CMakeFiles/DynArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DynArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DynArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DynArray.dir/build: DynArray

.PHONY : CMakeFiles/DynArray.dir/build

CMakeFiles/DynArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DynArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DynArray.dir/clean

CMakeFiles/DynArray.dir/depend:
	cd /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build /home/angellafalck/Desktop/EstructuraDatos1/EjercicioVector/build/CMakeFiles/DynArray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DynArray.dir/depend
