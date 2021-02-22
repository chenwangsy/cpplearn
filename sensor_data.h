/*
 * @Descripttion: L3 newFrame 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 14:21:35
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 16:56:06
 */
#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H




#include <memory>
using namespace std;

enum class KDataType
{
    SENSORDATA = 0,
    OBJ = 1,
    EGO = 2,

    END
};

class SensorData;
typedef shared_ptr<SensorData> SensorDataPtr;

class SensorData
{  
    friend SensorDataPtr copySensorDataPtr(SensorDataPtr sptr, KDataType type);     //该类的友元函数
    using FuncPtr = SensorDataPtr (*)(SensorDataPtr, KDataType);

    public:
        virtual ~SensorData() {}

        static void addCopyPtrFunc(FuncPtr funcPtr, KDataType type);
    private:
        static FuncPtr funcPtr_[(int)KDataType::END];

};

SensorDataPtr copySensorDataPtr(SensorDataPtr sptr, KDataType type);


//----------------------------------------------------------------------------------

class Object : public SensorData
{
    public:
        double posx_ = 0;
        double posy_ = 0;
        double velx_ = 0;
        double vely_ = 0;
        int trackId_ = 0;
        static void initCopyObjectPtrFunc();
};
typedef shared_ptr<Object> ObjectPtr;






class Vehicle : public SensorData
{
    public:
        double velx_ = 0;
        double vely_ = 0;
        double acc_ = 0;
        static void initCopyVehiclePtrFunc();
};
typedef shared_ptr<Vehicle> VehiclePtr;




#endif // !SENSOR_DATA_H