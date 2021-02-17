/*
 * @Descripttion: 
 * @version: 
 * @Author: CWSY
 * @Date: 2020-11-14 11:41:38
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-17 18:45:06
 */
#include <iostream>
#include "design_pattern_24.h"

using namespace std;


int main()
{
	Request r1("qingjia2", "1tianjia", 33);
	Manager* m1 = new NormalManager("cwsy");
	Manager* m2 = new MajorDomo("renfan");
	Manager* m3 = new GeneralManager("liangfenghua");

	m1->setSuperiorManager(m2);
	m2->setSuperiorManager(m3);

	m1->dealRequest(r1);
}



