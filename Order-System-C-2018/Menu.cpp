#include"menu.h"
//����˵������� 
void Menu::readmenu(){
	ifstream infile("C:\\Users\\sx\\Desktop\\�γ����\\�γ����\\menu.txt");
	while(infile>>menu.id>>menu.name>>menu.price){
		menum.push_back(menu);
	}
	infile.close();
}
//���Ӳ˵� 
void Menu::add_menu(){
	int id;
	string name;
	double price;
	cout<<"��������Ʒ�ı��  ����	�۸�"<<endl;
	cin>>id>>name>>price;
	menu.id=id;
	menu.name=name; 
	menu.price=price;
	menum.push_back(menu);
}
//���Ҳ˵� 
void Menu::find_menu(){
	cout<<"����Ҫ���ҵĲ˵�����:"<<endl;
	string name;
	cin>>name;
	for(it=menum.begin();it!=menum.end();it++)
	{
		if((*it).name==name)
		cout<<(*it).id<<"\t"<<(*it).name<<"\t"<<(*it).price<<endl;
	} 
}
//�޸Ĳ˵� 
void Menu::change_menu(){
	cout<<"������Ҫ�޸ļ۸�Ĳ������޸ĺ�ļ۸�:"<<endl;
	string name;
	double price;
	cin>>name>>price;
	for(it=menum.begin();it!=menum.end();it++){
		if((*it).name==name)
		(*it).price=price;
	}	
}
//ɾ���˵� 
void Menu::delete_menu(){
	cout<<"������Ҫɾ���Ĳ���:"<<endl;
	string name;
	cin>>name;
	for(it=menum.begin();it!=menum.end();it++){
		if((*it).name==name)
		menum.erase(it);
	}
}
//����˵� 
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