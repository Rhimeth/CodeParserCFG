# Locate LLVM and Clang 18
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
include_directories(${LLVM_INCLUDE_DIR}/clang)
link_directories(${LLVM_LIBRARY_DIR})

# Add your executable
add_executable(CFGProject ${SOURCES})
target_link_libraries(CFGProject clang)
