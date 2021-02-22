/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 15:18:53
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 16:53:55
 */

#include "sensor_data.h"
SensorData::FuncPtr SensorData::funcPtr_[(int)KDataType::END] = {nullptr};

void SensorData::addCopyPtrFunc(FuncPtr funcPtr, KDataType type)
{
    funcPtr_[(int)type] = funcPtr;
}

SensorDataPtr copySensorDataPtr(SensorDataPtr sptr, KDataType type)
{
    if (SensorData::funcPtr_[(int)type] == nullptr)
    {
        throw runtime_error("this func not been settled! ");
    }

    return (SensorData::funcPtr_[(int)type])(sptr, type);
}

SensorDataPtr copyObjectPtr(SensorDataPtr sptr, KDataType type)
{
    if(type != KDataType::OBJ)
    {
        throw runtime_error("type error");
    }
    ObjectPtr p = dynamic_pointer_cast<Object>(sptr);
    return make_shared<Object>(*p);
}


SensorDataPtr copyVehiclePtr(SensorDataPtr sptr, KDataType type)
{
    if(type != KDataType::EGO)
    {
        throw runtime_error("type error");
    }
    VehiclePtr p = dynamic_pointer_cast<Vehicle>(sptr);
    return make_shared<Vehicle>(*p);
}



void Object::initCopyObjectPtrFunc()
{
    SensorData::addCopyPtrFunc(copyObjectPtr, KDataType::OBJ);
}





void Vehicle::initCopyVehiclePtrFunc()
{
    SensorData::addCopyPtrFunc(copyVehiclePtr, KDataType::EGO);
}

