# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/share/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/share/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiberiu/Desktop/rasterizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiberiu/Desktop/rasterizer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rasterizer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rasterizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rasterizer.dir/flags.make

CMakeFiles/rasterizer.dir/main.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rasterizer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rasterizer.dir/main.cpp.o -c /home/tiberiu/Desktop/rasterizer/main.cpp

CMakeFiles/rasterizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiberiu/Desktop/rasterizer/main.cpp > CMakeFiles/rasterizer.dir/main.cpp.i

CMakeFiles/rasterizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiberiu/Desktop/rasterizer/main.cpp -o CMakeFiles/rasterizer.dir/main.cpp.s

CMakeFiles/rasterizer.dir/wrapper.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/wrapper.cpp.o: ../wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rasterizer.dir/wrapper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rasterizer.dir/wrapper.cpp.o -c /home/tiberiu/Desktop/rasterizer/wrapper.cpp

CMakeFiles/rasterizer.dir/wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/wrapper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiberiu/Desktop/rasterizer/wrapper.cpp > CMakeFiles/rasterizer.dir/wrapper.cpp.i

CMakeFiles/rasterizer.dir/wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/wrapper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiberiu/Desktop/rasterizer/wrapper.cpp -o CMakeFiles/rasterizer.dir/wrapper.cpp.s

CMakeFiles/rasterizer.dir/graphics.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/graphics.cpp.o: ../graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rasterizer.dir/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rasterizer.dir/graphics.cpp.o -c /home/tiberiu/Desktop/rasterizer/graphics.cpp

CMakeFiles/rasterizer.dir/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiberiu/Desktop/rasterizer/graphics.cpp > CMakeFiles/rasterizer.dir/graphics.cpp.i

CMakeFiles/rasterizer.dir/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiberiu/Desktop/rasterizer/graphics.cpp -o CMakeFiles/rasterizer.dir/graphics.cpp.s

CMakeFiles/rasterizer.dir/utils.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rasterizer.dir/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rasterizer.dir/utils.cpp.o -c /home/tiberiu/Desktop/rasterizer/utils.cpp

CMakeFiles/rasterizer.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiberiu/Desktop/rasterizer/utils.cpp > CMakeFiles/rasterizer.dir/utils.cpp.i

CMakeFiles/rasterizer.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiberiu/Desktop/rasterizer/utils.cpp -o CMakeFiles/rasterizer.dir/utils.cpp.s

CMakeFiles/rasterizer.dir/mafs.cpp.o: CMakeFiles/rasterizer.dir/flags.make
CMakeFiles/rasterizer.dir/mafs.cpp.o: ../mafs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rasterizer.dir/mafs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rasterizer.dir/mafs.cpp.o -c /home/tiberiu/Desktop/rasterizer/mafs.cpp

CMakeFiles/rasterizer.dir/mafs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rasterizer.dir/mafs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tiberiu/Desktop/rasterizer/mafs.cpp > CMakeFiles/rasterizer.dir/mafs.cpp.i

CMakeFiles/rasterizer.dir/mafs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rasterizer.dir/mafs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tiberiu/Desktop/rasterizer/mafs.cpp -o CMakeFiles/rasterizer.dir/mafs.cpp.s

# Object files for target rasterizer
rasterizer_OBJECTS = \
"CMakeFiles/rasterizer.dir/main.cpp.o" \
"CMakeFiles/rasterizer.dir/wrapper.cpp.o" \
"CMakeFiles/rasterizer.dir/graphics.cpp.o" \
"CMakeFiles/rasterizer.dir/utils.cpp.o" \
"CMakeFiles/rasterizer.dir/mafs.cpp.o"

# External object files for target rasterizer
rasterizer_EXTERNAL_OBJECTS =

rasterizer: CMakeFiles/rasterizer.dir/main.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/wrapper.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/graphics.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/utils.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/mafs.cpp.o
rasterizer: CMakeFiles/rasterizer.dir/build.make
rasterizer: /usr/lib/x86_64-linux-gnu/libOpenGL.so
rasterizer: /usr/lib/x86_64-linux-gnu/libGLX.so
rasterizer: /usr/lib/x86_64-linux-gnu/libGLU.so
rasterizer: /usr/lib/x86_64-linux-gnu/libglut.so
rasterizer: CMakeFiles/rasterizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable rasterizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rasterizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rasterizer.dir/build: rasterizer

.PHONY : CMakeFiles/rasterizer.dir/build

CMakeFiles/rasterizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rasterizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rasterizer.dir/clean

CMakeFiles/rasterizer.dir/depend:
	cd /home/tiberiu/Desktop/rasterizer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiberiu/Desktop/rasterizer /home/tiberiu/Desktop/rasterizer /home/tiberiu/Desktop/rasterizer/cmake-build-debug /home/tiberiu/Desktop/rasterizer/cmake-build-debug /home/tiberiu/Desktop/rasterizer/cmake-build-debug/CMakeFiles/rasterizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rasterizer.dir/depend

