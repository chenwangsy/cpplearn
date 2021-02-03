/*
 * @Descripttion: 
 *              if class B wants to use class A's protected or private member(func or data),
 *         class B should make itself in class A's friend class declare(write the declare in class A),
 *         which means you can't use A's protected or private member is you can't get A's source code,
 *         this is kinda like a restriction.  also you should keep in mind that:
 *                      友元关系不具有传递性 友元关系不具有继承性 友元关系不具有相互性
 * 
 * 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-03 22:28:22
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-03 22:56:23
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Student
{   
    friend class StuInfoContainer;
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

class StuInfoContainer
{
    public:
        StuInfoContainer() = default;

        void addStuInfo(const Student &stu);
        void showStuInfo();
    private:
        vector<string> stuInfo_;    
};

void StuInfoContainer::addStuInfo(const Student &stu)
{
    stuInfo_.push_back(stu.combineNameAndNumber());
}

void StuInfoContainer::showStuInfo()
{
    for(const string &info : stuInfo_)
    {
        cout << info << endl;
    }
}