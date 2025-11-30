cmake_minimum_required(VERSION 3.28.3)

project(test_2)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wunused-const-variable
    -Wlogical-op
    -Wduplicated-cond
    -Wredundant-decls
    -Wnon-virtual-dtor
    -Woverloaded-virtual
    -Wsuggest-override
    -Wzero-as-null-pointer-constant
    -Wsign-promo
    -Wfloat-equal
    -Wcast-qual
    -Wcast-align
    -Wmissing-field-initializers
    -Werror
)

add_executable(task_1_fpi task_1_fpi.cpp)
add_executable(task_1_Newton task_1_Newton.cpp)
