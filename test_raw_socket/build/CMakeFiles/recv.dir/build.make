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
CMAKE_SOURCE_DIR = /home/huanyu/workspace/test/rawsocket_json/test_raw_socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build

# Include any dependencies generated for this target.
include CMakeFiles/recv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recv.dir/flags.make

CMakeFiles/recv.dir/recv.cpp.o: CMakeFiles/recv.dir/flags.make
CMakeFiles/recv.dir/recv.cpp.o: ../recv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recv.dir/recv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recv.dir/recv.cpp.o -c /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/recv.cpp

CMakeFiles/recv.dir/recv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recv.dir/recv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/recv.cpp > CMakeFiles/recv.dir/recv.cpp.i

CMakeFiles/recv.dir/recv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recv.dir/recv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/recv.cpp -o CMakeFiles/recv.dir/recv.cpp.s

CMakeFiles/recv.dir/recv.cpp.o.requires:

.PHONY : CMakeFiles/recv.dir/recv.cpp.o.requires

CMakeFiles/recv.dir/recv.cpp.o.provides: CMakeFiles/recv.dir/recv.cpp.o.requires
	$(MAKE) -f CMakeFiles/recv.dir/build.make CMakeFiles/recv.dir/recv.cpp.o.provides.build
.PHONY : CMakeFiles/recv.dir/recv.cpp.o.provides

CMakeFiles/recv.dir/recv.cpp.o.provides.build: CMakeFiles/recv.dir/recv.cpp.o


# Object files for target recv
recv_OBJECTS = \
"CMakeFiles/recv.dir/recv.cpp.o"

# External object files for target recv
recv_EXTERNAL_OBJECTS =

recv: CMakeFiles/recv.dir/recv.cpp.o
recv: CMakeFiles/recv.dir/build.make
recv: CMakeFiles/recv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recv.dir/build: recv

.PHONY : CMakeFiles/recv.dir/build

CMakeFiles/recv.dir/requires: CMakeFiles/recv.dir/recv.cpp.o.requires

.PHONY : CMakeFiles/recv.dir/requires

CMakeFiles/recv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recv.dir/clean

CMakeFiles/recv.dir/depend:
	cd /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huanyu/workspace/test/rawsocket_json/test_raw_socket /home/huanyu/workspace/test/rawsocket_json/test_raw_socket /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build /home/huanyu/workspace/test/rawsocket_json/test_raw_socket/build/CMakeFiles/recv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recv.dir/depend

