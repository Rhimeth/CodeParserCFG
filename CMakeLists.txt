cmake_minimum_required(VERSION 3.10)

# Project name
project(CFGGenerator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Clang/LLVM libraries
find_package(LLVM REQUIRED CONFIG)

# Include Clang headers
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Add source files
add_executable(cfg_generator cfg_generator.cpp)

# Link against Clang libraries
target_link_libraries(cfg_generator
    clangAST
    clangASTMatchers
    clangBasic
    clangFrontend
    clangTooling
)
