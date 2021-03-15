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
	vector<menuItem> menum;    //�����menuIitem������ 
	vector<menuItem>::iterator it;
	struct menuItem menu;
	Menu(){readmenu();}
	void readmenu();  //���ļ��ж�ȡ�˵� 
	void add_menu();       //���Ӻ������� 
	void find_menu();      //���Һ������� 
	void change_menu();    //�޸ĺ������� 
	void delete_menu();     //ɾ���������� 
	void savemenu();    //����˵����ļ��к������� 
    void display();    //����˵��������� 
    ~Menu(){savemenu();}
};