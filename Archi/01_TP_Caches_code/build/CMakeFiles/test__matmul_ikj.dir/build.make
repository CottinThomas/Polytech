# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build

# Include any dependencies generated for this target.
include CMakeFiles/test__matmul_ikj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test__matmul_ikj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test__matmul_ikj.dir/flags.make

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o: CMakeFiles/test__matmul_ikj.dir/flags.make
CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o: ../tests/matmul_ikj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o"
	/usr/lib64/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o -c /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/tests/matmul_ikj.cpp

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.i"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/tests/matmul_ikj.cpp > CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.i

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.s"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/tests/matmul_ikj.cpp -o CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.s

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.requires:

.PHONY : CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.requires

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.provides: CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.requires
	$(MAKE) -f CMakeFiles/test__matmul_ikj.dir/build.make CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.provides.build
.PHONY : CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.provides

CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.provides.build: CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o


# Object files for target test__matmul_ikj
test__matmul_ikj_OBJECTS = \
"CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o"

# External object files for target test__matmul_ikj
test__matmul_ikj_EXTERNAL_OBJECTS =

test__matmul_ikj: CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o
test__matmul_ikj: CMakeFiles/test__matmul_ikj.dir/build.make
test__matmul_ikj: CMakeFiles/test__matmul_ikj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test__matmul_ikj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test__matmul_ikj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test__matmul_ikj.dir/build: test__matmul_ikj

.PHONY : CMakeFiles/test__matmul_ikj.dir/build

CMakeFiles/test__matmul_ikj.dir/requires: CMakeFiles/test__matmul_ikj.dir/tests/matmul_ikj.cpp.o.requires

.PHONY : CMakeFiles/test__matmul_ikj.dir/requires

CMakeFiles/test__matmul_ikj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test__matmul_ikj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test__matmul_ikj.dir/clean

CMakeFiles/test__matmul_ikj.dir/depend:
	cd /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build /home/tp-home008/tcottin/Polytech/git/Polytech/Archi/01_TP_Caches_code/build/CMakeFiles/test__matmul_ikj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test__matmul_ikj.dir/depend

