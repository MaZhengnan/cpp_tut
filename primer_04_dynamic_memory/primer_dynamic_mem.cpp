
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include "primer_dynamic_mem.h"

using std::cout;
using std::endl;
using std::string;

/*
 * memory in computers involve the stack and heap
 * stack: int a;
 * heap: int* a = new int(1);
 *
 * pointer in memory
 * shared pointer
 * unique pointer
 * usually use unique pointer
 * */

void shared_pointer_func()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(10);
    std::shared_ptr<int> ptr_1(ptr); // copy construction
    cout << ptr.use_count()<< endl;
    cout << ptr_1.use_count() << endl;
    {
        std::shared_ptr<int> ptr_2(ptr); // copy construction
        cout << ptr.use_count()<< endl;
        cout << ptr_2.use_count() << endl;
    }
    cout << ptr.use_count()<< endl;
}


//////////////////////////////////////////////////////////
class A{
public:
    int* a_;
    string b_;
    A(int a, string b):a_(new int(a)),b_(b){
        cout << "in constructor" << endl;
    }

    /* shallow copy constructor
    A(const A& a)
    {
        this->a_ = a.a_;
    }
     */

    // deep copy constructor
    A(const A& a)
    {
        this->a_ = new int(*(a.a_));
    }

    ~A()
    {
        cout << "in destructor "<< b_ << endl;
        delete a_;
    }
};

void shallow_deep_copy()
{
    A a1(10,"a1");
    A a2(a1);
    cout << a1.b_ <<endl;
    cout << a1.a_ <<endl;
    cout << a2.b_ <<endl;
    cout << a2.a_ <<endl;
    cout<<"hello world"<<endl;
}

void test_func()
{
    std::unordered_map<int, int> my_map;
    //my_map.insert(1,10)
    my_map[1] = 10;
    my_map[3] = 30;
    my_map[5] = 3320;
    my_map[5] = 100;
    my_map[9] = 330;
    my_map[2] = 33330;
    cout << my_map.count(5) << endl;
    cout << my_map.count(3320) << endl;
    cout << my_map.count(2) << endl;
}



void empty_func_3()
{

}