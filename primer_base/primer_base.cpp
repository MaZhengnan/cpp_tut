#include "primer.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// chapter1.2 A first look at input/output
void io_library()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2
              << std::endl;
}

// chapter1.4.1 The while statement
void while_statement()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10)
    {
        sum += val; // assigns sum + val to sum
        ++val;      // add 1 to val
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}

// chapter1.4.2 The for statement
void for_statement()
{
    int sum = 0;
    // sum values from 1 through 10 inclusive
    for (int val = 1; val <= 10; ++val)
        sum += val; // equivalent to sum = sum + val
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}

// chapter1.4.3 Read unknown of input
void read_unknown_value_of_input()
{
    int sum = 0, value = 0;
    // read until end-of-file, calculating a running total of all values read
    // end-of-file in windows: ctrl+z, unix: ctrl+d
    while (std::cin >> value) sum += value; // equivalent to sum = sum + value
    std::cout << "Sum is: " << sum << std::endl;
}

// chapter2 Read unknown of input
void data_type()
{
    cout << "char: " << sizeof(char) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
}

// default argument
// inline doesn't have static and recursion in the function body
void default_argument(int a, int b, char c)
{
    cout << a << " " << b << " " << c << endl;
}

// constexpr
constexpr int get_size() { return 1; }

// assert debug
// need include <cassert>
// use "#define NDEBUG" before "include <cassert>" to disable it
//#define NDEBUG
#include <cassert>
void assert_use(int a)
{
    assert(a == 10);
    cout << a << endl;
}

// pointers to functions
bool is_short(const std::string& s1, const std::string& s2)
{
    return (s1.size() < s2.size());
}

bool (*pfunc)(const std::string& s1, const std::string& s2);

void pointer_to_function()
{
    pfunc = &is_short;
    cout << pfunc("abc", "abcd") << endl;
}

// NULL
void empty_func(){}