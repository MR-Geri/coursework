# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mr-geri/Проекты/c/two_course/coursework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mr-geri/Проекты/c/two_course/coursework

# Utility rule file for coursework_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/coursework_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/coursework_autogen.dir/progress.make

CMakeFiles/coursework_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mr-geri/Проекты/c/two_course/coursework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target coursework"
	/usr/bin/cmake -E cmake_autogen /home/mr-geri/Проекты/c/two_course/coursework/CMakeFiles/coursework_autogen.dir/AutogenInfo.json Debug

coursework_autogen: CMakeFiles/coursework_autogen
coursework_autogen: CMakeFiles/coursework_autogen.dir/build.make
.PHONY : coursework_autogen

# Rule to build all files generated by this target.
CMakeFiles/coursework_autogen.dir/build: coursework_autogen
.PHONY : CMakeFiles/coursework_autogen.dir/build

CMakeFiles/coursework_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coursework_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coursework_autogen.dir/clean

CMakeFiles/coursework_autogen.dir/depend:
	cd /home/mr-geri/Проекты/c/two_course/coursework && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mr-geri/Проекты/c/two_course/coursework /home/mr-geri/Проекты/c/two_course/coursework /home/mr-geri/Проекты/c/two_course/coursework /home/mr-geri/Проекты/c/two_course/coursework /home/mr-geri/Проекты/c/two_course/coursework/CMakeFiles/coursework_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coursework_autogen.dir/depend

