# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/thomas/Polytech/Archi/TP/TP_SIMD_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build

# Include any dependencies generated for this target.
include CMakeFiles/test__sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test__sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test__sum.dir/flags.make

CMakeFiles/test__sum.dir/tests/sum.cpp.o: CMakeFiles/test__sum.dir/flags.make
CMakeFiles/test__sum.dir/tests/sum.cpp.o: ../tests/sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test__sum.dir/tests/sum.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test__sum.dir/tests/sum.cpp.o -c /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum.cpp

CMakeFiles/test__sum.dir/tests/sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test__sum.dir/tests/sum.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum.cpp > CMakeFiles/test__sum.dir/tests/sum.cpp.i

CMakeFiles/test__sum.dir/tests/sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test__sum.dir/tests/sum.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum.cpp -o CMakeFiles/test__sum.dir/tests/sum.cpp.s

CMakeFiles/test__sum.dir/tests/sum.cpp.o.requires:

.PHONY : CMakeFiles/test__sum.dir/tests/sum.cpp.o.requires

CMakeFiles/test__sum.dir/tests/sum.cpp.o.provides: CMakeFiles/test__sum.dir/tests/sum.cpp.o.requires
	$(MAKE) -f CMakeFiles/test__sum.dir/build.make CMakeFiles/test__sum.dir/tests/sum.cpp.o.provides.build
.PHONY : CMakeFiles/test__sum.dir/tests/sum.cpp.o.provides

CMakeFiles/test__sum.dir/tests/sum.cpp.o.provides.build: CMakeFiles/test__sum.dir/tests/sum.cpp.o


# Object files for target test__sum
test__sum_OBJECTS = \
"CMakeFiles/test__sum.dir/tests/sum.cpp.o"

# External object files for target test__sum
test__sum_EXTERNAL_OBJECTS =

test__sum: CMakeFiles/test__sum.dir/tests/sum.cpp.o
test__sum: CMakeFiles/test__sum.dir/build.make
test__sum: CMakeFiles/test__sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test__sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test__sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test__sum.dir/build: test__sum

.PHONY : CMakeFiles/test__sum.dir/build

CMakeFiles/test__sum.dir/requires: CMakeFiles/test__sum.dir/tests/sum.cpp.o.requires

.PHONY : CMakeFiles/test__sum.dir/requires

CMakeFiles/test__sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test__sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test__sum.dir/clean

CMakeFiles/test__sum.dir/depend:
	cd /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/Polytech/Archi/TP/TP_SIMD_code /home/thomas/Polytech/Archi/TP/TP_SIMD_code /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles/test__sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test__sum.dir/depend

