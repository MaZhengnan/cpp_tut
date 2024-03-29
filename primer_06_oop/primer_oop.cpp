#include "primer_oop.h"
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

// object-oriented programming

/* parent class */
class Boo
{
public:
    string ISBN;
    /*
     * you can comment or uncomment 'virtual' to look over the
     * different performances
     * */
    virtual void func()
    {
        cout << "Boo" << endl;
    }
    ~Boo(){}
};

class ComicBoo: public Boo
{
public:
    // dynamic dispatch
    // dynamic binding
    void func() override
    {
        cout << "Comic Boo" << endl;
    }
    ~ComicBoo(){}
};

class ActionBoo: public Boo
{
public:
    void func() override
    {
        cout << "Action Boo" << endl;
    }
    ~ActionBoo(){}
};

void virtual_func()
{
    ComicBoo cb;
    ActionBoo ab;
    Boo* b1 = (Boo*)&cb;
    Boo& b2 = ab;
    b1->func();
    b2.func();
}



/* parent class */
class Book
{
public:
    string ISBN;
    /*
     * you can comment or uncomment 'virtual' to look over the
     * different performances
     * */
    Book(string isbn):ISBN(isbn){
        cout << "in book constructor" << endl;
    }

    Book()
    {
        cout << "in explicit book constructor" << endl;
    }

    virtual void func()
    {
        cout << "Book" << endl;
    }
    /*
     * pure virtual function
     * if define a pure virtual function in a class
     * the class is the abstract base class
     * 不能被实例化
     * */

    virtual void func1()=0;
    ~Book(){
        cout << "in book destructor" << endl;
    }
};

class ComicBook: public Book
{
public:
// dynamic dispatch
// dynamic binding
    bool picture_;
    ComicBook(bool picture):Book("133"),picture_(picture){
        cout << "in comic book constructor" << endl;
    }
    void func() override
    {
        cout << "Comic Book" << endl;
    }

    void func1() override
    {
        cout << "in Comic Book pure virtual function" << endl;
    }
    ~ComicBook(){
        cout << "in comic book destructor" << endl;
    }
};

class ActionBook: public Book
{
public:
    void func() override
    {
        cout << "Action Book" << endl;
    }
    void func1() override
    {
        cout << "Action Book pure virtual function" << endl;
    }
    ~ActionBook(){
        cout << "in action book destructor" << endl;
    }
};

/*
 * constructing -> base -> derive class
 * destructing -> derive -> base class
 * */
void basic_class()
{
    ComicBook cb(true);
    Book& b = cb;
    b.func();
    b.Book::func();
    // Book b1("123"); // error!!!
}




void empty_func_6() {}