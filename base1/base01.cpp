#include "base1.h"
#include <iostream>

/*
 * function name base01()
 * 顶层 const 和 底层 const
 * const int *const p = new int(10);
 * 底层        顶层
 * 在这个例子中 的指针部分，
 * 第一个const 是代表指向的值不可变，底层const
 * 第二个const 代表指向的地址不可变，但是可以修改指向的值，顶层const
 * reference c++ Primer:
 * 当执行对象拷贝操作时，常量的顶层const不受什么影响，而底层const必须一致
 *
 * 引用部分 const原则
 * 1.引用不是对象，是一个别名，不遵循上述原则
 * 2.常量引用在左侧，右面可以接任何东西
 * 3.非常量引用=常量，报错
 * 4.引用在等号的右侧，忽略引用
 * 5.非常量=常量引用 正确
 */
void base01()
{
    std::cout << "Base knowladge base_1 ---- const" << std::endl;
    /* Global use*/
    const int a = 10;
    int b = a;

    /* Pointer */
    int *p0 = new int(10);
    int *const p1 = new int(10);
    const int *p2 = new int(10);
    const int *const p3 = new int(10);

    int *pp0 = p0;
    int *const pp1 = p0;
    const int *pp2 = p0;
    const int *const pp3 = p0;

    // pp0 = p1; //error,
    // pp1 = p1; //error 指向的地址不可变
    *pp1 = 20; //指向的值可变
    pp2 = p2;  //指向可变
    //*pp2 = 100; //error 指向的值不可变
    //*pp3 = 100; //error
    // pp3 = p3; //error 指向的值和指向都不可变

    // a的定义是一个顶层const，但是代表指向的地址中的值不可变，取地址就变成了底层const，因为a的地址中的值不能变
    // int *pp4 = &a; //error
    const int *pp4 = &a;
    std::cout << "const pointer p: " << *p0 << std::endl;

    /* Reference */
    /* 引用原则2 */
    const int &r0 = 20; //
    const int &r1 = b; //虽然r1是常量，b不是，但是这只代表不能用r1修改b

    /* 引用原则3*/
    /* r2是一个代表其他对象的别名，但是20不是对象，是一个常量 */
    // int &r2 =20; // error
    // int &r2 = a; //error,同上，a的别名r2不是常量，但是a是常量

    /* 引用原则4*/
    /* 这时r0 的定义相当于 const int r0 = 20; */
    // int &r3 = r0; //error

    /* 引用原则5*/
    int c = r0; // 顶层const可以忽略，就是可以拷贝
    std::cout << "---------------------" << std::endl;
}

