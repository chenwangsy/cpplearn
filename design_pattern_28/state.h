/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 17:46:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 18:53:31
 */

#ifndef _STATE_H
#define _STATE_H
 
class Person;
 
class State
{
public:
	virtual void GetManConclusion(Person* concreteElementA){};
	virtual void GetWomanConclusion(Person* concreteElementB){};
};
 
class Success :public State
{
public:
	void GetManConclusion(Person* concreteElementA) override;
	void GetWomanConclusion(Person* concreteElementB) override;;
};
 
class Failing :public State
{
public:
	void GetManConclusion(Person* concreteElementA) override;
	void GetWomanConclusion(Person* concreteElementB) override;
};
 
class Amativeness :public State
{
public:
	void GetManConclusion(Person* concreteElementA) override;
	void GetWomanConclusion(Person* concreteElementB) override;
};
#endif