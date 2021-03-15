#pragma once
#include<iostream>
#include<string>
#include"date.h"
#include<windows.h>
#include"Order.h"
#include"Menu.h"
using namespace std;
class Control{	
public:	
	Order k;
	OrderManager manager;
	Cdate nowtime;
	Menu nowmenu;
	void run();
	void run1();
	void run2();
	void customer();
	void setorder();
 	void delorder();
 	void seaorder();
};
