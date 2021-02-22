/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 17:53:01
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 18:50:27
 */

#ifndef _OBJECTSTRUCTURE_H_
#define _OBJECTSTRUCTURE_H_
 
#include"person.h"
#include"state.h"
#include <vector>
#include <string>
#include <iostream>
 
class ObjectStructure
{
private:
	std::vector<Person*> elements;
public:
	ObjectStructure(){}
	~ObjectStructure();
 
	void Attach(Person*);
	void Display(State*);
};
 
#endif