# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/huanyu/workspace/test/tcp_json/test_json

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huanyu/workspace/test/tcp_json/test_json/build

# Include any dependencies generated for this target.
include CMakeFiles/test_json.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_json.dir/flags.make

CMakeFiles/test_json.dir/test_json.cpp.o: CMakeFiles/test_json.dir/flags.make
CMakeFiles/test_json.dir/test_json.cpp.o: ../test_json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanyu/workspace/test/tcp_json/test_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_json.dir/test_json.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_json.dir/test_json.cpp.o -c /home/huanyu/workspace/test/tcp_json/test_json/test_json.cpp

CMakeFiles/test_json.dir/test_json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_json.dir/test_json.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanyu/workspace/test/tcp_json/test_json/test_json.cpp > CMakeFiles/test_json.dir/test_json.cpp.i

CMakeFiles/test_json.dir/test_json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_json.dir/test_json.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanyu/workspace/test/tcp_json/test_json/test_json.cpp -o CMakeFiles/test_json.dir/test_json.cpp.s

CMakeFiles/test_json.dir/test_json.cpp.o.requires:

.PHONY : CMakeFiles/test_json.dir/test_json.cpp.o.requires

CMakeFiles/test_json.dir/test_json.cpp.o.provides: CMakeFiles/test_json.dir/test_json.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_json.dir/build.make CMakeFiles/test_json.dir/test_json.cpp.o.provides.build
.PHONY : CMakeFiles/test_json.dir/test_json.cpp.o.provides

CMakeFiles/test_json.dir/test_json.cpp.o.provides.build: CMakeFiles/test_json.dir/test_json.cpp.o


# Object files for target test_json
test_json_OBJECTS = \
"CMakeFiles/test_json.dir/test_json.cpp.o"

# External object files for target test_json
test_json_EXTERNAL_OBJECTS =

test_json: CMakeFiles/test_json.dir/test_json.cpp.o
test_json: CMakeFiles/test_json.dir/build.make
test_json: CMakeFiles/test_json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huanyu/workspace/test/tcp_json/test_json/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_json.dir/build: test_json

.PHONY : CMakeFiles/test_json.dir/build

CMakeFiles/test_json.dir/requires: CMakeFiles/test_json.dir/test_json.cpp.o.requires

.PHONY : CMakeFiles/test_json.dir/requires

CMakeFiles/test_json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_json.dir/clean

CMakeFiles/test_json.dir/depend:
	cd /home/huanyu/workspace/test/tcp_json/test_json/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huanyu/workspace/test/tcp_json/test_json /home/huanyu/workspace/test/tcp_json/test_json /home/huanyu/workspace/test/tcp_json/test_json/build /home/huanyu/workspace/test/tcp_json/test_json/build /home/huanyu/workspace/test/tcp_json/test_json/build/CMakeFiles/test_json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_json.dir/depend

