/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 18:50:41
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 18:54:18
 */

#include "object_structure.h"
#include <iterator>
 
ObjectStructure::~ObjectStructure()
{
	std::vector<Person* >::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		delete *it;
}
 
void ObjectStructure::Attach(Person* element)
{
	elements.push_back(element);
}
 
void ObjectStructure::Display(State* visitor)
{
	std::vector<Person* >::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		(*it)->Accept(visitor);
}