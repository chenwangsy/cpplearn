/*
 * @Descripttion: 
 * @version: 
 * @Author: CWSY
 * @Date: 2020-11-14 11:41:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-27 22:30:27
 */
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
using namespace std;

//设计模式 第1章内容 简单工厂模式
#if 0
class BaseOper
{
    public:
        BaseOper(double num1, double num2) : num1_(num1), num2_(num2) {}
        virtual double cal() const=0;
    protected:
        double num1_;
        double num2_;
};
typedef BaseOper* BaseOperPtr;

class Add : public BaseOper
{
    public:
        Add(double num1, double num2) : BaseOper(num1, num2) {}
        double cal() const override {return num1_ + num2_;}
};

class Sub : public BaseOper
{   
    public:
        Sub(double num1, double num2) : BaseOper(num1, num2) {}
        double cal() const override {return num1_ - num2_;}
};

class OperFactory
{   
    public:
        static OperFactory* getFactory()
        {
            if(operFactoryPtr == nullptr)
            {
                operFactoryPtr = new OperFactory();
            }
            return operFactoryPtr;
        }

        OperFactory() : add_(new Add(1, 2)), sub_(new Sub(3, 4))
        {
            
        }

    public:
        static OperFactory* operFactoryPtr;
        BaseOperPtr add_;
        BaseOperPtr sub_;
    
};
OperFactory* OperFactory::operFactoryPtr = nullptr;
#endif




//设计模式 第2章内容 商场促销--策略模式
#if 0
class BaseCash
{
    public:
        virtual double calCash(double money) const=0;
};

class CashRebate : public BaseCash
{   
    public:
        CashRebate(double rebate) : rebate_(rebate) {}
        double calCash(double money) const {return money * rebate_;}
    private:
        double rebate_;

};

class CashSub : public BaseCash
{   
    public:
        CashSub(int subCash) : subCash_(subCash) {}
        double calCash(double money) const {return money - subCash_;}
    private:
        double subCash_;
};

class Context
{
    public:
        Context(int choice)
        {
            switch (choice)
            {
            case 0:
                baseCashPtr_ = new CashRebate(0.6);
                break;
            
            case 1:
                baseCashPtr_ = new CashSub(200);
                break;
            }
        }

        double getResult(double money)
        {
            return baseCashPtr_->calCash(money);
        }
    private:
        BaseCash* baseCashPtr_;
};

#endif

class AbstractAssoStrategy
{
    public:
        void asso()
        {
            cout << "asso1" << endl;
            asso2();
            asso3();
        }
    private:
        virtual void asso2() const = 0;
        virtual void asso3() const
        {
            cout << "AbstractAssoStrategy::asso3" << endl;
        }
};

class FcAssoStrategy : public AbstractAssoStrategy
{
    void asso2() const
    {
        cout << "FcAssoStrategy::asso2" << endl;
    }
};

class FrAssoStrategy : public AbstractAssoStrategy
{   
    void asso2() const
    {
        cout << "FrAssoStrategy::asso2" << endl;
    }

    void asso3() const
    {
        cout << "FrAssoStrategy::asso3" << endl;
    }
};


#include "udp_receiver.h"




int main()
{      
    UdpReceiver rcv(13051);
    int counter = 0;
    while(++counter <= 10)
    {
        rcv.receive();
    }

    return 0;
}





