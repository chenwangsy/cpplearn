/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-17 17:01:22
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-17 18:24:51
 */

#include <iostream>
#include <string>
using namespace std;

class Request
{
    public:
        Request(const string &type, const string &content, int number) : type_(type), content_(content), number_(number) {}
        const string & getRequestType() const {return type_;}
        const string & getRequestContent() const {return content_;}
        int getRequestNumber() const {return number_;}

    private:
        string type_;
        string content_;
        int number_;
};

//-------------------------------------请求的处理者类型-----------------------------------

class Manager
{      

    public: 
        Manager(const string &name) : name_(name) {}
        void setSuperiorManager(Manager* superiorManager) {superiorManager_ = superiorManager;}
        virtual void dealRequest(const Request &request) const = 0;

    protected:
        string name_;
        Manager* superiorManager_;

};

class NormalManager : public Manager
{   
    public:
        NormalManager(const string &name) : Manager(name) {}

        virtual void dealRequest(const Request &request) const override
        {
            if (request.getRequestType() == "qingjia" && request.getRequestNumber() <= 2)
            {
                cout << "NormalManager " << name_ << " passed this request" << endl;
            }
            else
            {
                superiorManager_->dealRequest(request);
            }
            
        }
};

class MajorDomo : public Manager
{   
    public:
        MajorDomo(const string &name) : Manager(name) {}

        virtual void dealRequest(const Request &request) const override
        {
            if (request.getRequestType() == "qingjia" && request.getRequestNumber() <= 5)
            {
                cout << "MajorDomo " << name_ << " passed this request" << endl;
            }
            else
            {
                superiorManager_->dealRequest(request);
            }
            
        }
};

class GeneralManager : public Manager
{
    public:
        GeneralManager(const string &name) : Manager(name) {}

        virtual void dealRequest(const Request &request) const override
        {
            if (request.getRequestType() == "qingjia")
            {
                cout << "GeneralManager " << name_ << " passed this request" << endl;
            }
            else if (request.getRequestType() == "zhanggongzi")
            {   
                cout << "GeneralManager " << name_ << " passed this request up money: " << request.getRequestNumber() << endl;
            }
            else
            {
                cout << "nobody can solve this problem!!!" << endl;
            }
        }
};



