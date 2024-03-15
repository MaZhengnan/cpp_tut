

#include "box_operating.h"
#include "box.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void class_change_mode(Boxx& box)
{
    box.get_name();
    box.get_box_volume();
    /* If you use the change copy, there will be a destructor,
     * because it is a copy process, need to delay the old class */
    box.change_height_copy(20).change_height_ref(30);
    box.get_box_volume();
    box.change_height_ref(40).change_height_copy(30);
    box.get_box_volume();
    // box.message();
}

void class_move_constructor()
{
    Boxx box("toy", 1234, 1, 2, 3, true, "blue");
    Boxx a = box;
    Boxx b = std::move(box);
    box.get_box_volume(); // why it is running normally? when I moved the box!!
    a = box;
}

void box_operator()
{
    Boxx box_1("toy", 1234, 1, 2, 3, true, "blue");

    /*---------------------------------------------------------------------------*/
    // class_change_mode(box_1);
    class_move_constructor();
    /*---------------------------------------------------------------------------*/
    // Boxx box_2(box_1);
    // box_2.set_name("iphone");
}