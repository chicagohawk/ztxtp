# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20

# Include any dependencies generated for this target.
include src/CMakeFiles/XTPApiDemo.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/XTPApiDemo.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/XTPApiDemo.dir/flags.make

src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o: src/CMakeFiles/XTPApiDemo.dir/flags.make
src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o: src/FileUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o -c /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/FileUtils.cpp

src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.i"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/FileUtils.cpp > CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.i

src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.s"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/FileUtils.cpp -o CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.s

src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o: src/CMakeFiles/XTPApiDemo.dir/flags.make
src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o: src/quote_spi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o -c /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/quote_spi.cpp

src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.i"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/quote_spi.cpp > CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.i

src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.s"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/quote_spi.cpp -o CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.s

src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.o: src/CMakeFiles/XTPApiDemo.dir/flags.make
src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.o: src/strategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.o"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XTPApiDemo.dir/strategy.cpp.o -c /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/strategy.cpp

src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XTPApiDemo.dir/strategy.cpp.i"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/strategy.cpp > CMakeFiles/XTPApiDemo.dir/strategy.cpp.i

src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XTPApiDemo.dir/strategy.cpp.s"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/strategy.cpp -o CMakeFiles/XTPApiDemo.dir/strategy.cpp.s

src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o: src/CMakeFiles/XTPApiDemo.dir/flags.make
src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o: src/trade_spi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o -c /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/trade_spi.cpp

src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.i"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/trade_spi.cpp > CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.i

src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.s"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/trade_spi.cpp -o CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.s

src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o: src/CMakeFiles/XTPApiDemo.dir/flags.make
src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o: src/xtp_api_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o -c /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/xtp_api_demo.cpp

src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.i"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/xtp_api_demo.cpp > CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.i

src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.s"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/xtp_api_demo.cpp -o CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.s

# Object files for target XTPApiDemo
XTPApiDemo_OBJECTS = \
"CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o" \
"CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o" \
"CMakeFiles/XTPApiDemo.dir/strategy.cpp.o" \
"CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o" \
"CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o"

# External object files for target XTPApiDemo
XTPApiDemo_EXTERNAL_OBJECTS =

api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/FileUtils.cpp.o
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/quote_spi.cpp.o
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/strategy.cpp.o
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/trade_spi.cpp.o
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/xtp_api_demo.cpp.o
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/build.make
api/XTPApiDemo: src/CMakeFiles/XTPApiDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../api/XTPApiDemo"
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XTPApiDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/XTPApiDemo.dir/build: api/XTPApiDemo

.PHONY : src/CMakeFiles/XTPApiDemo.dir/build

src/CMakeFiles/XTPApiDemo.dir/clean:
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src && $(CMAKE_COMMAND) -P CMakeFiles/XTPApiDemo.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/XTPApiDemo.dir/clean

src/CMakeFiles/XTPApiDemo.dir/depend:
	cd /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20 /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20 /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src /Users/hanchen/Documents/XTP_API_20180305_1.1.16.20-clang/demo/XTPApiDemo-1.1.16.20/src/CMakeFiles/XTPApiDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/XTPApiDemo.dir/depend

