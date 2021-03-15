#include"menu.h"
//输出菜单到容器 
void Menu::readmenu(){
	ifstream infile("C:\\Users\\sx\\Desktop\\课程设计\\课程设计\\menu.txt");
	while(infile>>menu.id>>menu.name>>menu.price){
		menum.push_back(menu);
	}
	infile.close();
}
//增加菜单 
void Menu::add_menu(){
	int id;
	string name;
	double price;
	cout<<"请输入商品的编号  名字	价格"<<endl;
	cin>>id>>name>>price;
	menu.id=id;
	menu.name=name; 
	menu.price=price;
	menum.push_back(menu);
}
//查找菜单 
void Menu::find_menu(){
	cout<<"输入要查找的菜的名字:"<<endl;
	string name;
	cin>>name;
	for(it=menum.begin();it!=menum.end();it++)
	{
		if((*it).name==name)
		cout<<(*it).id<<"\t"<<(*it).name<<"\t"<<(*it).price<<endl;
	} 
}
//修改菜单 
void Menu::change_menu(){
	cout<<"请输入要修改价格的菜名和修改后的价格:"<<endl;
	string name;
	double price;
	cin>>name>>price;
	for(it=menum.begin();it!=menum.end();it++){
		if((*it).name==name)
		(*it).price=price;
	}	
}
//删除菜单 
void Menu::delete_menu(){
	cout<<"请输入要删除的菜名:"<<endl;
	string name;
	cin>>name;
	for(it=menum.begin();it!=menum.end();it++){
		if((*it).name==name)
		menum.erase(it);
	}
}
//保存菜单 
void Menu::savemenu(){
	ofstream outfile("menu.txt",ios::trunc);
	for(it=menum.begin();it!=menum.end();it++){
		outfile<<(*it).id<<"\t"<<(*it).name<<"\t"<<(*it).price<<endl;
	}
	outfile.close();
}
void Menu::display(){
	cout<<"id\t"<<"name\t"<<"price"<<endl;
	for(it=menum.begin();it!=menum.end();it++){
			cout<<setiosflags(ios::left)<<setw(8)<<(*it).id<<setw(8)<<(*it).name<<setw(8)<<(*it).price<<endl;
		} 
}