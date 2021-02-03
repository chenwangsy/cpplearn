/*
 * @Descripttion: 函数模板练习
 * 模板的特化可以认为有偏特化和全特化，但函数模板不支持偏特化，编译器无法通过，取而代之的实现是利用函数模板重载
 * 而对于函数模板的全特化，虽然其可以通过编译，但完全特化的函数模板可以被普通函数的重载版本所代替，因此最好使用普通函数
 * 总结：函数模板的特化主要靠函数模板重载(取代偏特化)以及函数重载(取代全特化)这两种方式实现
 * @version: 1.0.0
 * @Date: 2020-11-19 21:59:00
 */
#include<iostream>
using namespace std;

template<typename T>
void printer(T obj) {cout << "v1 " << "模板参数固定条件下最泛化的版本" << endl;}

#if 0 //v1和v2不可同时存在否则会引起模板匹配ambiguous
template<typename T>
void printer(const T& obj) {cout << "v2 " << "稍微特化的版本" << endl;}
#endif 

template<typename T> //函数模板不能使用像类模板一样的<模板偏特化> 取而代之的是<函数模板重载>
                     //<模板偏特化> void printer<T*>(T* p_obj) {cout << "v3 " << endl;}
void printer(T* p_obj) {cout << "v3 " << "函数模板重载的版本" << endl;}

template<>//c++不推荐这样的用法 因为模板参数已经全特化了，所以肯定可以被普通的重载函数所取代，但这不会报错
void printer<int>(int obj) {cout << "v4 " << "函数模板全特化的版本" << endl;}

void printer() {cout << "v5 " << "普通函数的版本,能匹配时优先级最高" << endl;}

template<typename T, typename... Types>//variadic templates 可以归纳为使用了函数模板的重载
void printer(T first, Types... args)
{
    cout << "v6 " << "可变参数模板版本，比起v1更加泛化，优先级是最低的" << endl;
    printer(args...);
}