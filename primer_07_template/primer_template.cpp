#include "primer_template.h"
#include <algorithm>
#include <cstddef>
#include <map>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>


using std::string;
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
T add(T a, T b)
{
    return a+b;
}

void template_overview()
{
    string a = "hello ";
    string b = "world";
    cout << add(a, b) << endl;
    cout << add(1.1,2.2) <<endl;
    cout << add(1, 2) <<endl;
}






void empty_func_7() {}