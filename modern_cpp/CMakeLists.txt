file(GLOB_RECURSE src CONFIGURE_DEPENDS *.cpp *.h)
add_library(modern_cpp STATIC ${src})