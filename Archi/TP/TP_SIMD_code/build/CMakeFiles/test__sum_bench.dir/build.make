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
include CMakeFiles/test__sum_bench.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test__sum_bench.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test__sum_bench.dir/flags.make

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o: CMakeFiles/test__sum_bench.dir/flags.make
CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o: ../tests/sum_bench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o -c /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum_bench.cpp

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum_bench.cpp > CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.i

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Polytech/Archi/TP/TP_SIMD_code/tests/sum_bench.cpp -o CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.s

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.requires:

.PHONY : CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.requires

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.provides: CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.requires
	$(MAKE) -f CMakeFiles/test__sum_bench.dir/build.make CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.provides.build
.PHONY : CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.provides

CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.provides.build: CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o


# Object files for target test__sum_bench
test__sum_bench_OBJECTS = \
"CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o"

# External object files for target test__sum_bench
test__sum_bench_EXTERNAL_OBJECTS =

test__sum_bench: CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o
test__sum_bench: CMakeFiles/test__sum_bench.dir/build.make
test__sum_bench: CMakeFiles/test__sum_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test__sum_bench"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test__sum_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test__sum_bench.dir/build: test__sum_bench

.PHONY : CMakeFiles/test__sum_bench.dir/build

CMakeFiles/test__sum_bench.dir/requires: CMakeFiles/test__sum_bench.dir/tests/sum_bench.cpp.o.requires

.PHONY : CMakeFiles/test__sum_bench.dir/requires

CMakeFiles/test__sum_bench.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test__sum_bench.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test__sum_bench.dir/clean

CMakeFiles/test__sum_bench.dir/depend:
	cd /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/Polytech/Archi/TP/TP_SIMD_code /home/thomas/Polytech/Archi/TP/TP_SIMD_code /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build /home/thomas/Polytech/Archi/TP/TP_SIMD_code/build/CMakeFiles/test__sum_bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test__sum_bench.dir/depend

