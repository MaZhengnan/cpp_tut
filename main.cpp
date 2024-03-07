

#include "primer_base/primer.h"
#include "primer_class/primer_class.h"
#include "primer_container/primer_container.h"
#include "primer_dynamic_memory/primer_dynamic_mem.h"

int main(int argv, char *argc[])
{
    primer_main();
    primer_class_main();
    primer_container_main();
    primer_dynamic_main();
    return 0;
}
