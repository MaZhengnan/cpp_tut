

#include "primer_01_base/primer.h"
#include "primer_02_class/primer_class.h"
#include "primer_03_container/primer_container.h"
#include "primer_04_dynamic_memory/primer_dynamic_mem.h"
#include "primer_05_copy_ctrl/primer_copy_ctrl.h"
#include "primer_06_oop/primer_oop.h"
#include "primer_07_template/primer_template.h"
#include "modern_cpp/modernc_main.h"

int main(int argv, char *argc[])
{
    primer_main();
    primer_class_main();
    primer_container_main();
    primer_dynamic_main();
    primer_copy_ctrl_main();
    primer_oop_main();
    primer_template_main();
    modern_cpp_main();
    return 0;
}
