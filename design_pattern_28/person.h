
#ifndef _PERSON_H_
#define _PERSON_H_
 
class State;
 
class Person
{
public:
	virtual void Accept(State* visitor){};
};
 
class Man :public Person
{
	void Accept(State* visitor);
};
 
class Woman :public Person
{
	void Accept(State* visitor);
};
 
#endif