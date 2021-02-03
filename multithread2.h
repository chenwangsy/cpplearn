/*
 * @Descripttion: 一个线程写数据 一个线程读数据 
 *                利用到了condition_variavle 和 notify_all 和 wait_for 这三个多线程类型和函数
 * @version:0.1
 * @Author: sueRimn
 * @Date: 2021-02-01 20:43:21
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-01 22:05:54
 */
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include <string>
#include <map>

using namespace std;

class SensorRawmsg
{
    public:
        SensorRawmsg() = default;
        ~SensorRawmsg() {}
        void writeData(const vector<int> &data);
        vector<int> readData();

    private:
        mutex m_;
        condition_variable cv_;
        vector<int> data_;
        bool dataHasBeenRead_ = false;
};

void SensorRawmsg::writeData(const vector<int> &data)
{
    unique_lock<mutex> uniqLock(m_);
    data_.clear();
    data_.resize(data.size());
    for(size_t i = 0; i < data.size(); ++i)
    {
        data_[i] = data[i];
    }
    dataHasBeenRead_ = false;
    cv_.notify_all();
}

vector<int> SensorRawmsg::readData()
{   
    vector<int> res;
    unique_lock<mutex> uniqLock(m_);
    if(dataHasBeenRead_)
    {
        cv_status status = cv_.wait_for(uniqLock, chrono::milliseconds(10));
        switch (status)
        {
        case cv_status::no_timeout:
            dataHasBeenRead_ = true;
            res = data_;
            break;
        
        case cv_status::timeout:
            cout << "time out " << endl;
            res = vector<int>();
            res.push_back(0);
            break;
        }
        return res;

    }
    else
    {
        dataHasBeenRead_ = true;
        return data_;
    }

}

//-------------------------------------------------------------------------------------------


class DataWriter
{

    public:
        DataWriter(SensorRawmsg *pdata) : pData_(pdata) {}
        
        void startThreadFunc();
        
    private:
        void threadFunc();
        void write(const vector<int> &data) {pData_->writeData(data);}
        SensorRawmsg *pData_;


};

void DataWriter::startThreadFunc()
{
    thread t(&DataWriter::threadFunc, this);
    t.detach();
}

void DataWriter::threadFunc()
{
    int count = 0; 
    while(1)
    {   
        this_thread::sleep_for(chrono::milliseconds(100));
        vector<int> data;
        data.push_back(++count);
        data.push_back(++count);
        write(data);
    }
}

//--------------------------------------------------------------------------------

class DataReader
{
    public:
        DataReader(SensorRawmsg *pdata) : pData_(pdata) {}
        
        void startThreadFunc();
        
    private:
        void threadFunc();
        vector<int> read() {return pData_->readData();}
        SensorRawmsg *pData_;
};

void DataReader::startThreadFunc()
{
    thread t(&DataReader::threadFunc, this);
    t.detach();
}
void DataReader::threadFunc()
{
    while (1)
    {   
        this_thread::sleep_for(chrono::milliseconds(50));
        vector<int> res = read();
        for(const int &num : res)
            cout << num << ", ";
        cout << endl;
    }
}