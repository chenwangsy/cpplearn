/*
 * @Descripttion: 
 *          when use a friend function, you should put the prototype of the function into the class,
 *          then you can use the protected or private member(function and data) in this function,
 *          obviously, you should have a class object in this friend function, for example, you can 
 *          deliver a object in this function's paramter, like what was written below.
 * 
 * @version: 0.1
 * @Author: cwsy
 * @Date: 2021-02-03 22:00:29
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-03 22:27:39
 */
#include <string>
#include <iostream>
using namespace std;

class Student
{   
    friend void printStudent(const Student &stu);
    public:
        explicit Student(int number) : number_(number) {}
        Student(int number, string name) : number_(number), name_(name) {}


    private:
        string combineNameAndNumber() const;
        int number_;
        string name_; 
};

string Student::combineNameAndNumber() const
{
    return to_string(number_) + ":" + name_;
}


void printStudent(const Student &stu)
{
    cout << stu.combineNameAndNumber() << endl;
}
