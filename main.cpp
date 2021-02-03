/*
 * @Descripttion: 
 * @version: 
 * @Author: CWSY
 * @Date: 2020-11-14 11:41:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-03 22:47:31
 */

#include "friend_class.h"



int main()
{   
    StuInfoContainer info;
    info.addStuInfo(Student(1,"535cw"));
    info.addStuInfo(Student(12,"c53w"));
    info.addStuInfo(Student(13,"c535w"));
    info.addStuInfo(Student(1452,"c434w"));
    info.addStuInfo(Student(1324,"cww"));

    info.showStuInfo();
    
    




    return 0;
}





