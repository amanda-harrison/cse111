# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amandaharrison/cse111/starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amandaharrison/cse111/starter/build

# Include any dependencies generated for this target.
include CMakeFiles/function_timer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/function_timer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/function_timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/function_timer.dir/flags.make

CMakeFiles/function_timer.dir/codegen:
.PHONY : CMakeFiles/function_timer.dir/codegen

CMakeFiles/function_timer.dir/examples/function_timer.cpp.o: CMakeFiles/function_timer.dir/flags.make
CMakeFiles/function_timer.dir/examples/function_timer.cpp.o: /Users/amandaharrison/cse111/starter/examples/function_timer.cpp
CMakeFiles/function_timer.dir/examples/function_timer.cpp.o: CMakeFiles/function_timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/amandaharrison/cse111/starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/function_timer.dir/examples/function_timer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/function_timer.dir/examples/function_timer.cpp.o -MF CMakeFiles/function_timer.dir/examples/function_timer.cpp.o.d -o CMakeFiles/function_timer.dir/examples/function_timer.cpp.o -c /Users/amandaharrison/cse111/starter/examples/function_timer.cpp

CMakeFiles/function_timer.dir/examples/function_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/function_timer.dir/examples/function_timer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amandaharrison/cse111/starter/examples/function_timer.cpp > CMakeFiles/function_timer.dir/examples/function_timer.cpp.i

CMakeFiles/function_timer.dir/examples/function_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/function_timer.dir/examples/function_timer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amandaharrison/cse111/starter/examples/function_timer.cpp -o CMakeFiles/function_timer.dir/examples/function_timer.cpp.s

# Object files for target function_timer
function_timer_OBJECTS = \
"CMakeFiles/function_timer.dir/examples/function_timer.cpp.o"

# External object files for target function_timer
function_timer_EXTERNAL_OBJECTS =

function_timer: CMakeFiles/function_timer.dir/examples/function_timer.cpp.o
function_timer: CMakeFiles/function_timer.dir/build.make
function_timer: CMakeFiles/function_timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/amandaharrison/cse111/starter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable function_timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/function_timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/function_timer.dir/build: function_timer
.PHONY : CMakeFiles/function_timer.dir/build

CMakeFiles/function_timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/function_timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/function_timer.dir/clean

CMakeFiles/function_timer.dir/depend:
	cd /Users/amandaharrison/cse111/starter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amandaharrison/cse111/starter /Users/amandaharrison/cse111/starter /Users/amandaharrison/cse111/starter/build /Users/amandaharrison/cse111/starter/build /Users/amandaharrison/cse111/starter/build/CMakeFiles/function_timer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/function_timer.dir/depend

