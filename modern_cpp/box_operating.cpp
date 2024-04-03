

#include "box_operating.h"
#include "box.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void class_change_mode(Boxes &box) {
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

void class_move_constructor() {
    Boxes box("toy", 1234, 1, 2, 3);
    Boxes a = box;
    Boxes b = std::move(box);
    box.get_box_volume(); // why it is running normally? when I moved the box!!
    a = box;
}

void class_operator_overloaded(Boxes &box1, Boxes &box2) {
    cout << "If these two box volume are equal: " << (box1 == box2) << endl;
    box1 = box1 + box2;
    cout << "New height of box: " << box1.height_ << endl;

}

void box_operator() {
    Boxes box_1("toy", 1111, 1, 1, 1);
    Boxes box_2("toy", 1112, 1, 1, 1);
    Boxes box_3("telephone", 2111, 2, 2, 2);
    /*---------------------------------------------------------------------------*/
    // class_change_mode(box_1);
    // class_move_constructor();
    class_operator_overloaded(box_1, box_2);
    /*---------------------------------------------------------------------------*/
}