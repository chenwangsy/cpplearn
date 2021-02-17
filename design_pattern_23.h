/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-10 23:16:03
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-10 23:24:38
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// 烤肉师傅
class BarbecueMaster
{
    public:
        void MakeMutton()
        {
            std::cout << "烤羊腿喽" << std::endl;
        }
        void MakeChiken()
        {
            std::cout << "烤鸡肉喽" << std::endl;
        }
};

class Command
{
    protected:
        BarbecueMaster *pmaster_;
    public:
        Command(BarbecueMaster *p)
        {
            pmaster_ = p;
        }
        virtual void executeCmd() = 0;
};

class CommandMutton : public Command
{
    public:
        CommandMutton(BarbecueMaster *p) : Command(p) {}
        void executeCmd()
        {
            pmaster_->MakeMutton();
        }
};

class CommandChiken : public Command
{
    public:
        CommandChiken(BarbecueMaster *p) : Command(p) {}
        void executeCmd()
        {
            pmaster_->MakeChiken();
        }
};


//-----------------------------------------------------------
class Waiter
{
    private:
        std::vector<Command *> m_vec;
    public:
        ~Waiter()
        {
            for (auto it = m_vec.begin(); it != m_vec.end(); it++)
            {
                delete(*it);
            }
            m_vec.clear();
        }
        void add(Command * p)
        {
            m_vec.push_back(p);
        }
        void remove(Command * p)
        {
            auto it = find(m_vec.begin(), m_vec.end(), p);
            if (it != m_vec.end())
                m_vec.erase(it);
        }
        void submitCmd()
        {
            for (auto it = m_vec.cbegin(); it != m_vec.cend(); it++)
            {
                (*it)->executeCmd();
            }
        }
};