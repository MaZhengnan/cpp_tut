cmake_minimum_required(VERSION 3.18)
project(modern_cpp)
set(CMAKE_CXX_STANDARD 14)

# for base1/base02.cpp
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS -fno-elide-constructors)

add_subdirectory(base1)
add_subdirectory(primer_01_base)
add_subdirectory(primer_02_class)
add_subdirectory(primer_03_container)
add_subdirectory(primer_04_dynamic_memory)
add_subdirectory(primer_05_copy_ctrl)


add_executable(main main.cpp)
target_link_libraries(main PUBLIC base1
        primer_base
        primer_class
        primer_container
        primer_dynamic_memory
        primer_copy_ctrl)
