/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 17:38:09
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 19:06:27
 */
#include <iostream>
#include "person.h"
#include "state.h"
#include "object_structure.h"
using namespace std;

int main()
{
	ObjectStructure o;
 
	o.Attach(new Man());
	o.Attach(new Woman());
	o.Attach(new Man());
 
	Success v1;
	o.Display(&v1);
 
	Failing v2;
	o.Display(&v2);
 
	Amativeness v3;
	o.Display(&v3);
    return 0;
}