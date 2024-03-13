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

template <typename T>
class G
{
public:
    T g_;
    G(){}
    G(T g):g_(g){}
    G& func()
    {
        cout << "in func" <<endl;
        return *this;
    }
    G& func2();
    static int cnt;
};

template <typename T>
int G<T>::cnt = 0;

template <typename T>
G<T>& G<T>::func2()
{
    cout << "in func" <<endl;
    return *this;
}

void class_template()
{
    G<int> g1(1);
    g1.func();
    g1.func2();

    g1.cnt += 1;

    G<long> g2(2);
    G<long> g3(3);
    g2.cnt += 1;
    g3.cnt += 1;
    cout << "g1 cnt: "<< g1.cnt << endl;
    cout << "g2 cnt: "<< g2.cnt << endl;
    cout << "g3 cnt: "<< g3.cnt << endl;
}




template <typename T, typename F = std::less<T>>

int compare(const T& t1, const T& t2, F f=F())
{
    if(f(t1,t2))
    {
        return -1;
    }
    if(f(t2,t1))
    {
        return 1;
    }
    return 0;
}

template <typename T>
bool isBigger(const T& t1, const T& t2)
{
    return t1 > t2;
}


void template_default_argument()
{
    cout << compare<int>(1,2) << endl;
    cout << compare<int>(1,2, isBigger<int>) << endl;
}

class DebugDelete
{
public:
    template <typename T>
    void operator()(T* p)
    {
        cout << "I am going to delete it!" << endl;
        delete p;
    }
};


void template_nested()
{
    DebugDelete d;
    double *p = new double(1.0);
    d(p);
}

// controlling instantiations










void empty_func_7() {
    cout << "In folder 'primer_07_template'!!!" << endl;
}