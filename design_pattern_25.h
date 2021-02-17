/*
 * @Descripttion: 设计模式第25章 -> 中介者模式
 * @version: 0.1
 * @Author: CWSY
 * @Date: 2021-02-17 19:07:35
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-17 19:27:35
 */


#include <iostream>
#include <string>
using namespace std;


class Mediator;


//抽象人
class Person
{
    protected:
        Mediator *pMediator_; //中介
    public:
        virtual void setMediator(Mediator *pMediator) {pMediator_ = pMediator;} //设置中介
        virtual void sendMessage(string message) const = 0;    //向中介发送信息
        virtual void getMessage(string message) const = 0;     //从中介获取信息
};

class Mediator
{
public:
	virtual void Send(string message, const Person *person) = 0;
	virtual void SetA(Person *A) = 0;
	virtual void SetB(Person *B) = 0;
};

//租房者
class Renter: public Person
{
    public:
        void sendMessage(string message) const override { pMediator_->Send(message, this); }
        void getMessage(string message) const override { cout << "租房者收到信息" << message; }
};
//房东
class Landlord: public Person
{
    public:
        void sendMessage(string message) const override { pMediator_->Send(message, this); }
        void getMessage(string message) const override { cout << "房东收到信息：" << message; }
};

//---------------------------------------------------------------------------------

class HouseMediator : public Mediator
{
    private:
        Person *m_A; //租房者
        Person *m_B; //房东
    public:
        HouseMediator(): m_A(0), m_B(0) {}
        void SetA(Person *A) override { m_A = A; }
        void SetB(Person *B) override { m_B = B; }
        void Send(string message, const Person *person) override
        {
            if(person == m_A) //租房者给房东发信息
                m_B->getMessage(message); //房东收到信息
            else
                m_A->getMessage(message);
        }
};