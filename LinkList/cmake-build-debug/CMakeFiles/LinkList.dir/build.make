# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "F:\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\huwenzhuo\CLionProjects\LinkList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkList.dir/flags.make

CMakeFiles/LinkList.dir/main.c.obj: CMakeFiles/LinkList.dir/flags.make
CMakeFiles/LinkList.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LinkList.dir/main.c.obj"
	"F:\CLion 2019.2.4\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LinkList.dir\main.c.obj   -c C:\Users\huwenzhuo\CLionProjects\LinkList\main.c

CMakeFiles/LinkList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LinkList.dir/main.c.i"
	"F:\CLion 2019.2.4\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\huwenzhuo\CLionProjects\LinkList\main.c > CMakeFiles\LinkList.dir\main.c.i

CMakeFiles/LinkList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LinkList.dir/main.c.s"
	"F:\CLion 2019.2.4\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\huwenzhuo\CLionProjects\LinkList\main.c -o CMakeFiles\LinkList.dir\main.c.s

# Object files for target LinkList
LinkList_OBJECTS = \
"CMakeFiles/LinkList.dir/main.c.obj"

# External object files for target LinkList
LinkList_EXTERNAL_OBJECTS =

LinkList.exe: CMakeFiles/LinkList.dir/main.c.obj
LinkList.exe: CMakeFiles/LinkList.dir/build.make
LinkList.exe: CMakeFiles/LinkList.dir/linklibs.rsp
LinkList.exe: CMakeFiles/LinkList.dir/objects1.rsp
LinkList.exe: CMakeFiles/LinkList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LinkList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LinkList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkList.dir/build: LinkList.exe

.PHONY : CMakeFiles/LinkList.dir/build

CMakeFiles/LinkList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LinkList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LinkList.dir/clean

CMakeFiles/LinkList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\huwenzhuo\CLionProjects\LinkList C:\Users\huwenzhuo\CLionProjects\LinkList C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug C:\Users\huwenzhuo\CLionProjects\LinkList\cmake-build-debug\CMakeFiles\LinkList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkList.dir/depend
