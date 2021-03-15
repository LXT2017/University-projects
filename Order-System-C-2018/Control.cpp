#include"Control.h"
//一级菜单 
void Control::run(){
	int a;
	cout<<"----------------------欢迎来到本餐厅-------------------------" <<endl;
	cout<<"                    "<<nowtime.getcurrent()<<"                    "<<endl;
	cout<<"请选择"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"|1.订单管理        |"<<endl;
	cout<<"|2.修改菜单        |"<<endl;
	cout<<"|3.退出            |"<<endl;
	cout<<"-------------------"<<endl; 
	cin>>a;
	if(a==1)
		run1();
	if(a==2)
		run2();
}
//二级菜单 
void Control::run2(){
	int b;
	cout<<"请选择"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"|1.显示菜单              |"<<endl;
	cout<<"|2.修改菜单              |"<<endl;
	cout<<"|3.删除菜单              |"<<endl;
	cout<<"|4.增加菜单              |"<<endl;
	cout<<"|5.查找菜单              |"<<endl;
	cout<<"|6.返回上一级            |"<<endl;
	cout<<"--------------------------"<<endl;
	cin>>b;
	switch(b){
		case 1:nowmenu.display();run2();break;
		case 2:nowmenu.change_menu();run2();break;
		case 3:nowmenu.delete_menu();run2();break;
		case 4:nowmenu.add_menu();run2();break;
		case 5:nowmenu.find_menu();run2();break;
		case 6:system("pause");
               cout<<"按任意键返回......"<<endl;
		       system("CLS"); 
			   run();
			   break; 
	}
}
//二级菜单 
void Control::run1(){
	int b;
	cout<<"请选择"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"|1.新增订单                     |"<<endl;
	cout<<"|2.修改订单                     |"<<endl;
	cout<<"|3.删除订单                     |"<<endl;
	cout<<"|4.查找订单                     |"<<endl;
	cout<<"|5.返回上一级                   |"<<endl;
	cout<<"--------------------------------"<<endl;
	cin>>b;
	switch(b){
		case 1:customer();run1();break;
		case 2:setorder();run1();break;
		case 3:delorder();run1();break;
		case 4:seaorder();run1();break;
		case 5:system("pause");
               cout<<"按任意键返回......"<<endl;
		       system("CLS"); 
			   run();
			   break; 
	}
}
//顾客选项
void Control::customer(){
	Order::ordernumber++;
	int amount,id,c,price,num,discount;
	string name; 
	cout<<"打包or在店消费-------（1.打包  2.在店消费）"<<endl;
	cin>>c;
	if(c==1){ 
		string time,place;
		int phone,fee;
		cout<<"请输入送达时间  地点  联系方式  配送费送"<<endl;
		cin>>time>>place>>phone>>fee;
		TakeoutOrder takeoutorder(time,place,phone,fee);
		cout<<"请输入要点几份菜"<<endl;
		cin>>amount;
		for(int i=1;i<=amount;i++){
			cout<<"请输入菜名  价格  份数 折扣"<<endl;
			cin>>name>>price>>num>>discount;
			takeoutorder.add_food(name,price,num,discount);
		}
		Order* p=new TakeoutOrder(takeoutorder);
		p->n=Order::ordernumber;
		manager.add_order(p); 
	} 
	if(c==2){
		int tablenum,roomfee;
		cout<<"请输入餐桌号和包厢费"<<endl;
		cin>>tablenum>>roomfee;
		InsideOrder insideorder(tablenum,roomfee);
		cout<<"请输入要点几份菜"<<endl;
		cin>>amount;
		for(int i=1;i<=amount;i++){
			cout<<"请输入菜名  价格  份数 折扣"<<endl;
			cin>>name>>price>>num>>discount;
			insideorder.add_food(name,price,num,discount);
		}
		Order* p=new InsideOrder(insideorder);	
		p->n=Order::ordernumber;
		manager.add_order(p);
	}
} 
//修改订单 
void Control::setorder(){
	int number,price;
	string name; 
	cout<<"请输入要修改的订单编号  菜名  价格"<<endl;
 	cin>>number>>name>>price;
  	manager.set_order(number,name,price);
}
//删除订单
void Control::delorder(){
	int number;
	cout<<"请输入要删除的订单号"<<endl;
	cin>>number;
	manager.del_order(number);
} 
//查找订单
void Control::seaorder() {
	int number;
	cout<<"请输入要查找的订单号"<<endl;
	cin>>number;
	manager.search_order(number);
}