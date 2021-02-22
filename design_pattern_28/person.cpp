/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2021-02-21 18:04:41
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-21 18:51:04
 */

#include"person.h"
#include"state.h"
 
void Man::Accept(State* visitor)
{
	visitor->GetManConclusion(this);
}
 
void Woman::Accept(State* visitor)
{
	visitor->GetWomanConclusion(this);
}