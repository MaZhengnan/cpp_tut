cmake_minimum_required(VERSION 3.18)
project(modern_cpp)
set(CMAKE_CXX_STANDARD 17)

# for base1/base02.cpp
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS -fno-elide-constructors)

add_subdirectory(base1)
add_subdirectory(primer_base)
add_subdirectory(primer_class)
add_subdirectory(primer_container)
add_subdirectory(primer_dynamic_memory)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC base1
                                    primer_base
                                    primer_class
                                    primer_container
                                    primer_dynamic_memory)
