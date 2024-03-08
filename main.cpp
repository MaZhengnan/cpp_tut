

#include "primer_01_base/primer.h"
#include "primer_02_class/primer_class.h"
#include "primer_03_container/primer_container.h"
#include "primer_04_dynamic_memory/primer_dynamic_mem.h"
#include "primer_05_copy_ctrl/primer_copy_ctrl.h"

int main(int argv, char *argc[])
{
    primer_main();
    primer_class_main();
    primer_container_main();
    primer_dynamic_main();
    primer_copy_ctrl_main();
    return 0;
}
