#pragma once
#include<iostream>
#include<string>
#include<vector> 
#include"date.h"
#include<fstream>
#include<typeinfo>
using namespace std;
struct Food{
	string name;
	int  price,num,discount;
};
class Order{
protected:	
	
public:
	vector<Food> foodlist;
	Food food;
	static int ordernumber;
	int n;
	void add_food(string name,int price,int num,int discount);
	virtual void display();
}; 
class TakeoutOrder:public Order{
private:
	
public:
	string time,place;
	int phone,fee;
	TakeoutOrder(string time,string place,int phone,int fee);
	void display();
};
class InsideOrder:public Order{
private:
	
public:
	int tablenum;
	int roomfee;
	InsideOrder(int tablenum,int roomfee);
	void display();
};
class OrderManager{
private:
	Cdate time;
public:
	vector<Order*> Ordernumber;
	vector<Order*>::iterator it;
	void add_order(Order* order);
	void set_order(int number,string name,int price);
	void del_order(int number);
	void search_order(int number);
	~OrderManager();
};

