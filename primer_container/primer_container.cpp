#include "primer_container.h"
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
// Iterator
void iterator()
{
    std::vector<int> vec = {1, 2, 3};
    /*
     * 1 2 3 vec.end
     * vec.begin -> first element of the vector
     * vec.end -> one element pass the last element
     * 1. end invalid element -> terminate
     * 2. begin != end -> at least one element
     * 3. begin = end -> empty
     */
    // for (auto it = vec.begin(); it != vec.end(); it++)
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
    std::vector<int> vec1(5, -3);
    for (auto num : vec1)
    {
        cout << num << endl;
    }
    /*
     * common iterators
     * citerator
     * riterator
     */
    auto cit = vec.cbegin();
    cout << *cit << endl;
    /* rend() is the element before the first element */
    auto rit = vec.rbegin();
    cout << *rit << endl;

    cout << "compare ----------------------" << endl;
    std::vector<int> vec2 = {1, 2, 3};
    std::vector<int> vec3 = {1, 2, 3};
    /*
     * same size
     * same type
     * every element in the array should be same
     */
    cout << "compare two vectors: " << (vec2 == vec3) << endl;
}

// vector iterator application
void vector_iterator_application()
{
    std::vector<int> vec = {1, 2, 3};
    auto it = vec.begin() + 1;
    int i = 2;
    while (i != 0)
    {
        /* 正确代码 */
        it = vec.insert(it, 100);
        /*这种写法只插入一次，但是为什么打印出来的第一个数据是0*/
        // vec.insert(it, 100);
        i--;
    }
    for (const int& num : vec)
    {
        cout << num << endl;
    }
}

// forward list 单链表
#include <forward_list>
using std::forward_list;

void operate_forward_list()
{
    forward_list<int> my_list = {1, 2, 3, 4, 5};
    forward_list<int>::iterator prev = my_list.before_begin();
    forward_list<int>::iterator cur = my_list.begin();
    while (cur != my_list.end())
    {
        if (*cur % 2 == 0)
        {
            cur = my_list.erase_after(prev);
        }
        else
        {
            prev = cur;
            cur++;
        }
    }
    for (const int& num : my_list)
    {
        cout << num << endl;
    }
}

// vector resize
void vector_resize()
{
    std::vector<int> vec = {1, 2, 3};
    for (const int& num : vec)
    {
        cout << num << endl;
    }
    vec.resize(5, -1);
    cout << "after resize: " << endl;
    for (const int& num : vec)
    {
        cout << num << endl;
    }
}

// container operations may invalidate iterators
// push back 以后，vector重新开辟了空间，并且对其进行了扩容
// 这时，iterator就会失效，直到重新找到vec.begin
// Todo 如何避免这种情况？
void invalidate_iterators()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    cout << "at the beginning capacity" << vec.capacity() << endl;

    std::vector<int>::iterator vbegin = vec.begin();
    std::vector<int>::iterator vend = vec.end();

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << "---------------" << endl;
        cout << "vec capacity" << vec.capacity() << endl;
        cout << *it << endl;
        if (*it == 2)
        {
            cout << "push back is happening!" << endl;
            vec.push_back(100);
        }

        if (vbegin != vec.begin())
        {
            it = vec.begin() + 2;
            vbegin = vec.begin();
            cout << "vbegin is changed" << endl;
        }
        if (vend != vec.end())
        {
            vend = vec.end();
            cout << "vend is changed" << endl;
        }
    }
    for (const int& num : vec)
    {
        cout << num << " ";
    }
}
// capacity of vector grows
void capacity_of_vector_grows()
{
    std::vector<int> vec;
    int prev_capacity = 0;
    for (int i = 0; i < 10000; i++)
    {
        if (prev_capacity != vec.capacity())
        {
            cout << "capacity changed -> " << vec.capacity() << endl;
            prev_capacity = vec.capacity();
        }
        vec.push_back(i);
    }
}

// string operate
// Todo: if i want to find all the "b" position. how to do it?
void string_operate()
{
    string str = "abbcdvbb";
    size_t pos = str.find("b");
    cout << pos << endl;
}

// lambda function statement
/*
 * lambda function format
 * lambda = [capture list](parameter list)->return type {function body}
 */
// Todo: why is the third parameter of sort could pass a function as
// "wannabigger"
void lambda_function()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto wannabigger = [&](const int& lhs, const int& rhs) -> bool {
        return lhs > rhs;
    };
    std::sort(vec.begin(), vec.end(), wannabigger);
    for (const int& num : vec)
    {
        cout << num << " ";
    }
    int sz = 0;

    cout << "--------------------" << endl;
    auto my_lambda = [=]() { return sz; };
    sz = 100;
    cout << "lambda function capture by value: " << my_lambda() << endl;
    auto my_lambda_1 = [&]() { return sz; };
    cout << "lambda function capture by reference: " << my_lambda_1() << endl;
}

// associative container: map and set
using std::map;
void associative_container()
{
    map<int, int> m = {{1, 2}, {5, 9}};

    cout << m[1] << " " << m[5] << endl;
    cout << "Traverse the map " << endl;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << "find member in the map " << endl;
    auto it = m.find(9);
    if (it != m.end())
    {
        cout << it->second << endl;
    }
    else
    {
        cout << "cannot find it!" << endl;
    }
    cout << "multimap" << endl;
    std::multimap<int, int> mumap = {{1, 2}, {5, 9}, {5, 7}};
    cout << mumap.count(5) << endl;
}

// pair and compare maps customarily
//#include <pair>
using std::pair;

class A
{
public:
    int a_;
    A(int a) : a_(a) {}
};

bool AWannaBigger(const A& a1, const A& a2) { return a1.a_ > a2.a_; }

void pair_customarily_compare()
{
    pair<int, int> p1 = {1, 2};
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << "pair print" << endl;
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second.first << " " << p2.second.second
         << endl;
    cout << "map print" << endl;
    map<A, int, decltype(AWannaBigger)*> my_map(AWannaBigger);
    my_map.insert({A(1), 1});
    my_map.insert({A(2), 2});
    my_map.insert({A(3), 3});
    my_map.insert({A(4), 4});
    for (auto it = my_map.begin(); it != my_map.end(); it++)
    {
        cout << it->second << endl;
    }
}

void empty_func_2() {}