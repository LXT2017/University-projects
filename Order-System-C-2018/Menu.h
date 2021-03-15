#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip> 
using namespace std;
struct menuItem{
	int id;
	string name;
	double price;
}; 
class Menu{
public:
	vector<menuItem> menum;    //定义个menuIitem的容器 
	vector<menuItem>::iterator it;
	struct menuItem menu;
	Menu(){readmenu();}
	void readmenu();  //从文件中读取菜单 
	void add_menu();       //增加函数声明 
	void find_menu();      //查找函数声明 
	void change_menu();    //修改函数声明 
	void delete_menu();     //删除函数声明 
	void savemenu();    //保存菜单到文件中函数声明 
    void display();    //输出菜单函数声明 
    ~Menu(){savemenu();}
};