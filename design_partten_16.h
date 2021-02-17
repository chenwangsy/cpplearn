/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-08 00:02:03
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-08 00:10:56
 */
#ifndef _STATE_PATTERN_
#define _STATE_PATTERN_
#include <iostream>
#include <memory>
using namespace std;
class Work;
class State
{
public:
	virtual void WriteProgram(Work*) = 0;
	virtual ~State() {};
};
typedef shared_ptr<State> StatePtr;

class Work
{
public:
	Work(const int iHour = 0) :m_iHour(iHour) {};
	int GetHour()const { return m_iHour; }
	void SetHour(const int iHour) { m_iHour = iHour; }

	void BeginWork() { m_spState->WriteProgram(this); }
	void SetState(StatePtr spState) { m_spState = spState; }
private:
	int m_iHour;
	StatePtr m_spState;
};


class RestState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		std::cout << "当地时间：" << pWork->GetHour() << "点 下班回家" << std::endl;
	}
};

class SleepingState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		if (pWork->GetHour() < 23)
		{
			std::cout << "当地时间：" << pWork->GetHour() << "点 不行了，睡着了" << std::endl;
		}
		else
		{
			pWork->SetState(StatePtr(new RestState()));
			pWork->BeginWork();
		}
	}
};

class EveningState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		if (pWork->GetHour() < 21)
		{
			std::cout << "当地时间：" << pWork->GetHour() << "点 加班哦，疲累之极" << std::endl;
		}
		else
		{
			pWork->SetState(StatePtr(new SleepingState()));
			pWork->BeginWork();
		}
	}
};

class AfterNoonState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		if (pWork->GetHour() < 17)
		{
			std::cout << "当地时间：" << pWork->GetHour() << "点 下午状态还不错，继续努力" << std::endl;
		}
		else
		{
			pWork->SetState(StatePtr(new EveningState()));
			pWork->BeginWork();
		}
	}
};

class NoonState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		if (pWork->GetHour() < 13)
		{
			std::cout << "当地时间：" << pWork->GetHour() << "点 饿了，午饭；犯困，午休。" << std::endl;
		}
		else
		{
			pWork->SetState(StatePtr(new AfterNoonState()));
			pWork->BeginWork();
		}
	}
};

class ForenoonState :public State
{
public:
	void WriteProgram(Work* pWork)
	{
		if (pWork->GetHour() < 12)
		{
			std::cout << "当地时间：" << pWork->GetHour() << "点 上午工作，精神百倍" << std::endl;
		}
		else
		{
			pWork->SetState(StatePtr(new NoonState()));
			pWork->BeginWork();
		}
	}
};
#endif // !_STATE_PATTERN_