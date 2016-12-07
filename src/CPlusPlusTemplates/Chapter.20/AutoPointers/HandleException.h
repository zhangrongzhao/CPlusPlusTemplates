#include "../stdafx.h"

//void do_two_things_1(){
//	Something* first = new Something;
//	first->perform();
//
//	Something* second = new Something;
//	second->perform();
//
//	delete first;
//	delete second;
//}
//
//
//void do_two_things_2(){
//	Something* first = 0;
//	Something* second = 0;
//	try{
//		first = new Something;
//		second = new Something;
//
//		//用*ptr进行一些操作
//		first->perform();
//		second->perform();
//	}
//	catch (...){
//		delete first;
//		delete second;
//		throw;//重新抛出被捕获的异常
//	}
//
//	delete first;
//	delete second;
//}