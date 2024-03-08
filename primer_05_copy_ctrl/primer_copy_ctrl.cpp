#include "primer_copy_ctrl.h"
#include <algorithm>
#include <cstddef>
#include <map>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;


/**
 * Whether it is rule of three or five
 * if you define one thing, you must define others
 *
 * rule of three
 *      copy constructor
 *      assign operator
 *      destructor
 *
 * rule of five
 *      copy constructor
 *      assign constructor
 *      destructor
 *      move constructor
 *      move assign operator
 * */


class B
{
public:
    int a_;
    B(int a):a_(a)
    {
        cout << "in direct constructor"<<endl;
    }
    B(const B& rhs)
    {
        this->a_ = rhs.a_;
        cout<<"in copy constructor"<<endl;
    }
    ~B()
    {
        cout << "in destructor"<<endl;
    }
};

void copy_constructor_func()
{
    B b1(1); // direct construction
    B b2(b1);   // copy construction
    B b3 = b2;  // copy construction
}



class Foo
{
public:
    int a_;
    Foo(int a):a_(a)
    {
        cout << "in direct constructor"<<endl;
    }
    Foo(const Foo& foo)
    {
        this->a_ = foo.a_;
        cout<<"in copy constructor"<<endl;
    }
    Foo& operator=(const Foo& foo)
    {
        cout<<"in copy assignment constructor"<<endl;
        this->a_ = foo.a_;
        return *this;
    }
    ~Foo()
    {
        cout << "in destructor"<<endl;
    }
};


// operator 用法？
void copy_assignment_func()
{
    Foo foo1(1);
    Foo foo2 = foo1;
    Foo foo3(1);
    foo3 = foo2;
}


class Res
{
public:
    int *resource_;
    size_t *count_;

    Res(int resource):resource_(new int(resource))
    {
        cout << "in direct constructor"<<endl;
        this->count_ = new size_t(1);
    }
    Res(const Res& res)
    {
        this->resource_ = res.resource_;
        this->count_ = res.count_;
        *(this->count_) += 1;

        cout<<"update this->count: "<< *(this->count_) << endl;
    }

    ~Res()
    {
        *(this->count_) -= 1;
        if(*(this->count_) == 0)
        {
            cout << "this->count_"<< endl;
            delete this->resource_;
            delete this->count_;
        }
        cout << "in destructor"<<endl;

    }
};

void virtual_shared_pointer_func()
{
    Res res1(1);
    Res res2(res1);
    Res res3(res1);
    Res res4(res1);
    Res res5(res1);

    cout << "how many people are pointing at it -> " << *(res3.count_) << endl;

}


void empty_func_5() {}