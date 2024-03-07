#include "primer_class.h"
#include <ostream>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void friend_func();
class Box;
// initialization happen before assign
// if there is a constant, must initial it in initialization
class BoxFriend
{
public:
    int high_;
    int a_;
    const int b_;
    BoxFriend(int high) : high_(high), b_(10) {}
    BoxFriend(int high, int a, int b)
        : high_(high), a_(a), b_(10) // initialization
    {
        this->high_ = high; // assign
        this->a_ = a;
        // this->b_ = b;
    }
    ~BoxFriend() = default;
    static void func();
    static void func_no_friend();
};

/*
 * access control:
 * public
 * private
 * protected
 */
class Box
{
    friend void friend_func();
    // friend class BoxFriend;
    friend void BoxFriend::func();

public:
    int length_;
    // constructor
    // explicit Box(string name, int len) : name_(name), length_(len)
    Box(string name, int len) : name_(name), length_(len)
    {
        this->mutable_test = 10;
        this->type_ = 1;
        cout << "This is the constructor of " << this->name_ << endl;
    }
    ~Box() { cout << "This is the destructor of " << this->name_ << endl; }

    void print_box_length() const { cout << this->length_ << endl; }

    Box& combine(const Box& rhs)
    {
        this->length_ += rhs.length_;
        return *this;
    }
    // because of const,  must add "mutable" before "mutable_test"
    void change_mutable_test() const
    {
        cout << "------mutable--------" << endl;
        cout << "before: " << this->mutable_test << endl;
        this->mutable_test = 100;
        cout << "after: " << this->mutable_test << endl;
    }

    int get_type() const { return this->type_; }

    Box change_copy_mode(int a)
    {
        this->type_ = a;
        cout << "change type in copy mode: " << this->type_ << endl;
        return *this; // return copy of the class
    }

    Box& change_ref_mode(int a)
    {
        this->type_ = a;
        cout << "change type in copy mode: " << this->type_ << endl;
        return *this; // return exactly of the class
    }

    Box& change_ref_mode_1(int a)
    {
        this->type_ = a;
        cout << "change type in copy mode: " << this->type_ << endl;
        return *this; // return exactly of the class
    }

    Box& display()
    {
        this->type_ = 100;
        cout << "in non-const display: " << this->type_ << endl;
        return *this;
    }

    const Box& display() const
    {
        cout << "in const display: " << this->type_ << endl;
        return *this;
    }

private:
    string name_;
    int type_;
    mutable int mutable_test;
};

// It isn't recommended
void friend_func()
{
    Box box("box_friend", 1);
    string str = box.name_;
    cout << "This is the friend function to get private member of box: " << str
         << endl;
}

// basic of class and friend function
void class_base()
{
    Box box("box", 10);
    Box box1("box1", 100);
    box.combine(box1);
    // box = box.combine(box1);
    cout << box.length_ << endl;
    box.print_box_length();
    box1.print_box_length();
    friend_func();
}

// mutable and function return *this
// copy change to ref change process:
// 1. Box box_temp = box.change_copy_mode
// 2. box_temp.change_ref_mode || change_ref_mode实际改变的是这个box_temp

// ref change to ref change process:
// box.change_copy_mode(20)
// box.change_copy_mode(30)
void mutable_return_this()
{
    Box box("box", 10);
    box.change_mutable_test();
    cout << "--------------------------" << endl;
    box.change_ref_mode(20).change_ref_mode_1(30);
    cout << "copy change -> ref change"
         << " " << box.get_type() << endl;
    cout << "--------------------------" << endl;
    box.change_copy_mode(20).change_ref_mode(30);
    cout << "copy change -> ref change"
         << " " << box.get_type() << endl;
}

// const test
void const_test()
{
    Box box("box", 10);
    const Box box1("box1", 10);

    box.display();
    box1.display();
}

// friend class
void BoxFriend::func()
{
    Box box("box", 10);
    cout << "in friend function: type " << box.type_ << endl;
}
void BoxFriend::func_no_friend()
{
    Box box("box", 10);
    // cout << "in friend function: type " << box.type_ << endl;
    cout << "in non-friend function" << endl;
}

void friend_class()
{
    BoxFriend box_friend(1);
    box_friend.func();
    box_friend.func_no_friend();
}

// delegate constructor to reduce the code

class NonDefault
{
public:
    string str_;
    NonDefault(string str) : str_(str) {}
    NonDefault() = default;
};

class SalesClass
{
public:
    int a_ = 0;
    bool b_ = false;
    long c_ = 0;

    static int static_member;
    NonDefault
        non_default; //这时有报错，必须要在这个class中加入default constructor
    SalesClass(int a, bool b, long c) : a_(a), b_(b), c_(c)
    {
        cout << "in three arguments" << endl;
    }
    SalesClass(int a, bool b) : SalesClass(a, b, 100)
    {
        cout << "in two arguments" << endl;
    }
    explicit SalesClass(int a) : SalesClass(a, true)
    {
        cout << "in one arguments" << endl;
    }
    SalesClass() = default;
};

void func(const SalesClass &sales_class)
{
    cout << "print class a_: " << sales_class.a_ << endl;
    cout << "in function of sales class print" << endl;
}

void delegate_constructor()
{
    SalesClass sales_data(10);
    func(SalesClass(20));
    //这里编译器给做了隐式转换，不想做这种转换，要在constructor加 explicit
    // func(20);
}

// static member variables
// we must define and initial each static data member outside the class body
int SalesClass::static_member = 10;
void static_member_variables()
{
    SalesClass sales_data1(10);
    SalesClass sales_data2(20);
    cout << sales_data1.static_member << " " << sales_data2.static_member
         << endl;

    /* maybe this statement doesn't have the warning */
    /* It's best to use the static member by class itself rather than by the instance */
    cout << SalesClass::static_member << endl;

    cout << "print static member if not define a class: "
         << SalesClass::static_member << endl;
}

// file operator
#include <fstream>

void file_operator_fstream()
{
    std::ofstream os("mzn.txt", std::ios::app);
    os << "hello world\n";
    os << "This is a test file!\n";

    // buffer
    os.flush();
    os.close();

    std::ifstream is("mzn.txt");
    string str;
    getline(is, str);
    cout << str << endl;
}

#include <sstream>
void file_operator_sstream()
{
    string raw_string = "hello world";
    std::stringstream ss(raw_string);
    int count = 0;
    string word;
    while (ss >> word)
    {
        count++;
    }
    cout << "number of words in raw_string: " << count << endl;
}

void empty_func_1() {}