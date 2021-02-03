/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-01-31 18:54:52
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-01-31 23:06:54
 */
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include <string>
#include <map>
using namespace std;

enum class SENSOR_FLAG
{   
    None = 0,
    FC = 1,
    FR = 2,
};

struct DataForFusion
{   
    friend class FcSensorProcessor;
    friend class FrSensorProcessor;
    public:
        DataForFusion()
        {
            objs_[SENSOR_FLAG::FC] = "";
            objs_[SENSOR_FLAG::FR] = "";
        }

        void print()
        {
            for(auto i : objs_)
            {
                cout << i.second << endl;
            }
        }
    
    private:
        void update(SENSOR_FLAG flag)
        {   
            unique_lock<mutex> uniqLock(mutex_);
            switch (flag)
            {
            case SENSOR_FLAG::FC:
                objs_[SENSOR_FLAG::FC] += "fc1";
                break;
            
            case SENSOR_FLAG::FR:
                objs_[SENSOR_FLAG::FR] += "fr2";
                break;
            }
        }

    private:
        map<SENSOR_FLAG, string> objs_;
        mutex mutex_;
};

class AbstractSensorProcessor
{   
    public:
        AbstractSensorProcessor(DataForFusion *pdata, SENSOR_FLAG flag) : pDataForFusion_(pdata), flag_(flag) {}
    
        virtual ~AbstractSensorProcessor() {};
        virtual void write() const = 0;
        virtual void startThreadFunc() const = 0;

    protected:
        DataForFusion *pDataForFusion_;
        SENSOR_FLAG flag_ = SENSOR_FLAG::None;
};

class FcSensorProcessor : public AbstractSensorProcessor
{   
    public:
        FcSensorProcessor(DataForFusion *pdata, SENSOR_FLAG flag) : AbstractSensorProcessor(pdata, flag) {}
        virtual void write() const override
        {
            pDataForFusion_->update(flag_);
        }

        void startThreadFunc() const
        {
            thread t(&FcSensorProcessor::threadFunc, this);
            cout << "FcThreadId is -> " << t.get_id() << endl;
            t.detach();
        }

        void threadFunc() const
        {
            for(int i = 0; i < 3 ; i++)
            {
                write();
            }
        }

};

class FrSensorProcessor : public AbstractSensorProcessor
{
    public:
        FrSensorProcessor(DataForFusion *pdata, SENSOR_FLAG flag) : AbstractSensorProcessor(pdata, flag) {}
        void write() const override
        {
            pDataForFusion_->update(flag_);
        }

        void startThreadFunc() const
        {   
            thread t(&FrSensorProcessor::threadFunc, this);
            cout << "FrThreadId is -> " << t.get_id() << endl;
            t.detach();
        }

        void threadFunc() const
        {
            for(int i = 0; i < 5 ; i++)
            {
                write();
            }
        }
};



