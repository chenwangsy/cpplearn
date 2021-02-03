/*
 * @Descripttion: 
 * @version: 
 * @Author: CWSY
 * @Date: 2020-11-14 11:41:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-01 22:47:14
 */
#include "mutithread3.h"




int main()
{   
    SensorRawmsg *p_rawmsg1 = new SensorRawmsg;
    SensorRawmsg *p_rawmsg2 = new SensorRawmsg;
    DataWriter wt;
    wt.addSensorRawmsgPtr(0, p_rawmsg1);
    wt.addSensorRawmsgPtr(1, p_rawmsg2);
    DataReader rd1(p_rawmsg1);
    DataReader rd2(p_rawmsg2);

    wt.startThreadFunc();
    rd1.startThreadFunc();
    rd2.startThreadFunc();

    while(1)
    {
        this_thread::sleep_for(5s);
    }



    return 0;
}





