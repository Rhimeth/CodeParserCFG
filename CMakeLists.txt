cmake_minimum_required(VERSION 3.10)
project(CFGProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find Clang libraries
find_package(Clang REQUIRED)

# Include directories for Clang
include_directories(${Clang_INCLUDE_DIRS})
link_directories(${Clang_LIBRARY_DIRS})

add_definitions(${LLVM_DEFINITIONS})

# Add executable and link libraries
add_executable(CFGProject src/main.cpp src/CFG.cpp src/CFGBuilder.cpp src/ASTConsumer.cpp)
target_link_libraries(CFGProject ${Clang_LIBRARIES})
