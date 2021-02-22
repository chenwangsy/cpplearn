/*
 * @Descripttion: 
 * @version: 
 * @Author: CWSY
 * @Date: 2020-11-14 11:41:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-22 21:55:33
 */
#include <iostream>
using namespace std;

int main()
{	

		
#if 0	//L3 new frame
	Vehicle::initCopyVehiclePtrFunc();
	Object::initCopyObjectPtrFunc();
	
	VehiclePtr p1 = make_shared<Vehicle>();
	p1->acc_ = 88;
	p1->velx_ = 99;
	ObjectPtr p2 = make_shared<Object>();
	p2->trackId_ = 13;
	SensorDataPtr p3 = copySensorDataPtr(p1, KDataType::EGO);
	VehiclePtr p3_real = dynamic_pointer_cast<Vehicle>(p3);
	ObjectPtr p4 = dynamic_pointer_cast<Object>(copySensorDataPtr(p2, KDataType::OBJ));

	cout << p1 << endl;
	cout << p3_real->acc_ << "  " << p3_real->velx_ << endl;
	cout << p4->trackId_ << endl;
	
	cout << (p1 != p3_real) << "  " << (p2 != p4) << endl;
#endif


	return 0;

}



