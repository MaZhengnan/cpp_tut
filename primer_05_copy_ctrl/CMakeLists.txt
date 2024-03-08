file(GLOB_RECURSE src CONFIGURE_DEPENDS *.cpp *.h)
add_library(primer_copy_ctrl STATIC ${src})