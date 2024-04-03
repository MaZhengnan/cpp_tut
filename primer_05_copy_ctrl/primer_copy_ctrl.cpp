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
using std::ostream;


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


class B {
public:
    int a_;

    B(int a) : a_(a) {
        cout << "in direct constructor" << endl;
    }

    B(const B &rhs) {
        this->a_ = rhs.a_;
        cout << "in copy constructor" << endl;
    }

    ~B() {
        cout << "in destructor" << endl;
    }
};

void copy_constructor_func() {
    B b1(1); // direct construction
    B b2(b1);   // copy construction
    B b3 = b2;  // copy construction
}


class Foo {
public:
    int a_;

    Foo(int a) : a_(a) {
        cout << "in direct constructor" << endl;
    }

    Foo(const Foo &foo) {
        this->a_ = foo.a_;
        cout << "in copy constructor" << endl;
    }

    Foo &operator=(const Foo &foo) {
        cout << "in copy assignment constructor" << endl;
        this->a_ = foo.a_;
        return *this;
    }

    ~Foo() {
        cout << "in destructor" << endl;
    }
};


// operator 用法？
void copy_assignment_func() {
    Foo foo1(1);
    Foo foo2 = foo1;
    Foo foo3(1);
    foo3 = foo2;
}


class Res {
public:
    int *resource_;
    size_t *count_;

    Res(int resource) : resource_(new int(resource)) {
        cout << "in direct constructor" << endl;
        this->count_ = new size_t(1);
    }

    Res(const Res &res) {
        this->resource_ = res.resource_;
        this->count_ = res.count_;
        *(this->count_) += 1;

        cout << "update this->count: " << *(this->count_) << endl;
    }

    ~Res() {
        *(this->count_) -= 1;
        if (*(this->count_) == 0) {
            cout << "this->count_" << endl;
            delete this->resource_;
            delete this->count_;
        }
        cout << "in destructor" << endl;

    }
};

void virtual_shared_pointer_func() {
    Res res1(1);
    Res res2(res1);
    Res res3(res1);
    Res res4(res1);
    Res res5(res1);

    cout << "how many people are pointing at it -> " << *(res3.count_) << endl;

}

class Bar {
    friend void swap(Bar &, Bar &);

public:
    int b_;

    Bar(int b) : b_(b) {}
};

class Sw {
    friend void swap(Sw &, Sw &);

public:
    string *s_;
    int a_;
    Bar bar_;

    Sw(const string s) : s_(new string(s)), a_(0), bar_(Bar(1)) {}

};

inline void swap(Bar &bar1, Bar &bar2) {
    cout << "in Bar swap" << endl;
    using std::swap;
    swap(bar1.b_, bar2.b_);
}

inline void swap(Sw &lhs, Sw &rhs) {
    cout << "in Sw swap" << endl;
    using std::swap;
    swap(lhs.s_, rhs.s_);
    swap(lhs.a_, rhs.a_);
    swap(lhs.bar_, rhs.bar_);
}


void swap_func() {
    Sw sw1("hello");
    Sw sw2("shoot");
    using std::swap;
    swap(sw1, sw2);
}

class Move {
public:
    int a_;

    Move(int a) : a_(a) {
        cout << "in direct construct: " << a << endl;
    }

    Move(const Move &move) {
        cout << "in copy constructor: " << move.a_ << endl;
        this->a_ = move.a_;
    }

    /*
     * move constructor
     * if "int a" changes to "int* a"
     * it's necessary to add the "a = nullptr" in move constructor
     * because it will delete the "a" pointer
     * */
    Move(Move &&move) noexcept {
        cout << "in move constructor: " << move.a_ << endl;
        this->a_ = move.a_;
    }

    ~Move() {
        cout << "in move destructor" << endl;
    }
};

void moving_object() {
    std::vector<Move> vec;
    vec.push_back(Move(10));
}

//===========================================================
// overloaded operator and conversions
class C {
    friend ostream &operator<<(ostream &, const C &);

public:
    int c_;
    std::vector<int> vec_{1, 2, 3};

    C(int c) : c_(c) {}

    /*
     * c1 + c2
     * left hand side --- right hand side
     * lhs rhs
     * */
    C &operator+(/* this */const C &c) {
        cout << "in operator+: " << c.c_ << endl;
        this->c_ += c.c_;
        return *this;
    }

    bool operator==(const C &c) const {
        cout << "in operator== " << endl;
        return (this->c_ == c.c_);
    }

    bool operator!=(const C &c) const {
        cout << "in operator!= " << endl;
        return this->c_ != c.c_;
    }

    /* Assignment operators can be overloaded.
     * Assignment operators.
     * regardless of parameter type,
     * must be defined as member functions
     * */
    C &operator=(std::initializer_list<int> list) {
        cout << "in operator=" << endl;
        for (const int &num: list) {
            vec_.push_back(num);
        }
        return *this;
    }

    /* subscript operator must be a member function
     * usually define two versions
     * one is non-const
     * the other one is const
     * */
    int &operator[](std::size_t index) {
        cout << "in non-const operator[]" << endl;
        return vec_[index];
    }

    /* subscript operator must be a member function */
    const int &operator[](std::size_t index) const {
        cout << "in const operator[]" << endl;
        return vec_[index];
    }

    ~C() {}
};

ostream &operator<<(ostream &os, const C &c) {
    cout << "in operate << " << endl;
    os << c.c_ << endl;
    return os;
}


void operator_overloaded_func() {
    C c1(1);
    C c2(2);
    C c3(1);
    C c4(2);
    /* operator+ */
    c2 = c1 + c2;
    cout << "c1: " << c1.c_ << endl;
    cout << "c2: " << c2.c_ << endl;
    /* operator<< */
    cout << c1 << endl;
    /* operator== */
    cout << (c3 == c4) << endl;
    cout << (c3 != c4) << endl;
    /* operator= */
    c3 = {4, 5, 6};
    cout << c3.vec_.size() << endl;

    /* operator[] */
    cout << c3[3] << endl;
    cout << c3.operator[](3) << endl;

    const C c5(2);
    cout << c5[2] << endl;
    cout << c5.operator[](2) << endl;
}


class Point {
public:
    int x_;
    int y_;

    Point(int x, int y) : x_(x), y_(y) {}

    Point &operator++() // prefix
    {
        x_ += 1;
        y_ += 1;
        cout << "prefix current sum is " << x_ << " " << y_ << endl;
        return *this;
    }

    Point &operator++(int) // postfix
    {
        x_ += 1;
        cout << "postfix current sum is " << x_ << " " << y_ << endl;
        return *this;
    }


};

/*
 * i++, ++i
 * 1. better to put this type of reloaded operator into class
 * 2. return reference when prefix++
 * 3. using int to distinguish between prefix & postfix
 * */
void operator_overloaded_prefix_func() {
    Point point(1, 1);
    ++point;
    point++;
}


class D {
public:
    int d_;

    D(int d) : d_(d) {}

    void func() {
        cout << "in class D func " << endl;
    }

    ~D() = default;
};

class E {
public:
    int e_;
    D *pd_;

    E(int e) : e_(e), pd_(new D(e)) {}

    D *operator->() {
        cout << "in operator->" << endl;
        return pd_;
    }

    int operator()() {
        cout << "in int operator()()" << endl;
        return (e_ + 1);
    }

    int operator()(int a) {
        cout << "in int operator()(int a)" << endl;
        return (e_ + a + 1);
    }

    string operator()(int a, int b) {
        cout << "in string operator()(int a, int b)" << endl;
        int res = (e_ + a + b + 1);
        return std::to_string(res);
    }
};


void operator_overloaded_member_access() {
    E e1(1);
    e1->func();
    cout << e1->d_ << endl;
    cout << e1() << endl;
    cout << e1(1) << endl;
    cout << e1(1, 2) << endl;
}


void empty_func_5() {}