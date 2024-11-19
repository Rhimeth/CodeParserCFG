cmake_minimum_required(VERSION 3.10)  # Specify the minimum version of CMake
project(CFGProject)  # Set the project name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/lib/llvm-14/include -L/usr/lib/llvm-14/lib")


# Locate LLVM and Clang
execute_process(
    COMMAND llvm-config --includedir
    OUTPUT_VARIABLE LLVM_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND llvm-config --libdir
    OUTPUT_VARIABLE LLVM_LIBRARY_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include directories for Clang
include_directories(${LLVM_INCLUDE_DIR})
include_directories(${LLVM_INCLUDE_DIR}/clang)
link_directories(${LLVM_LIBRARY_DIR})

# Define the source files
set(SOURCES
    src/main.cpp
    src/CFG.cpp
    src/CFGBuilder.cpp
    src/ASTConsumer.cpp
)

# Add the executable
add_executable(CFGProject ${SOURCES})

# Link Clang libraries
target_link_libraries(CFGProject clang)
