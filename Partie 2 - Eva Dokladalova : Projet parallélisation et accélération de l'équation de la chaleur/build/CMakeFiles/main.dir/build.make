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
CMAKE_SOURCE_DIR = "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/main.c.o   -c "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/main.c"

CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/main.c" > CMakeFiles/main.dir/main.c.i

CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/main.c" -o CMakeFiles/main.dir/main.c.s

CMakeFiles/main.dir/function.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/function.c.o: ../function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/function.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/function.c.o   -c "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/function.c"

CMakeFiles/main.dir/function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/function.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/function.c" > CMakeFiles/main.dir/function.c.i

CMakeFiles/main.dir/function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/function.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/function.c" -o CMakeFiles/main.dir/function.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/function.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.c.o
main: CMakeFiles/main.dir/function.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur" "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur" "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build" "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build" "/root/HPC-3-High_performance_computing/Partie 2 - Eva Dokladalova : Projet parallélisation et accélération de l'équation de la chaleur/build/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

