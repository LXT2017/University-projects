#include"Control.h"
//һ���˵� 
void Control::run(){
	int a;
	cout<<"----------------------��ӭ����������-------------------------" <<endl;
	cout<<"                    "<<nowtime.getcurrent()<<"                    "<<endl;
	cout<<"��ѡ��"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"|1.��������        |"<<endl;
	cout<<"|2.�޸Ĳ˵�        |"<<endl;
	cout<<"|3.�˳�            |"<<endl;
	cout<<"-------------------"<<endl; 
	cin>>a;
	if(a==1)
		run1();
	if(a==2)
		run2();
}
//�����˵� 
void Control::run2(){
	int b;
	cout<<"��ѡ��"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"|1.��ʾ�˵�              |"<<endl;
	cout<<"|2.�޸Ĳ˵�              |"<<endl;
	cout<<"|3.ɾ���˵�              |"<<endl;
	cout<<"|4.���Ӳ˵�              |"<<endl;
	cout<<"|5.���Ҳ˵�              |"<<endl;
	cout<<"|6.������һ��            |"<<endl;
	cout<<"--------------------------"<<endl;
	cin>>b;
	switch(b){
		case 1:nowmenu.display();run2();break;
		case 2:nowmenu.change_menu();run2();break;
		case 3:nowmenu.delete_menu();run2();break;
		case 4:nowmenu.add_menu();run2();break;
		case 5:nowmenu.find_menu();run2();break;
		case 6:system("pause");
               cout<<"�����������......"<<endl;
		       system("CLS"); 
			   run();
			   break; 
	}
}
//�����˵� 
void Control::run1(){
	int b;
	cout<<"��ѡ��"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"|1.��������                     |"<<endl;
	cout<<"|2.�޸Ķ���                     |"<<endl;
	cout<<"|3.ɾ������                     |"<<endl;
	cout<<"|4.���Ҷ���                     |"<<endl;
	cout<<"|5.������һ��                   |"<<endl;
	cout<<"--------------------------------"<<endl;
	cin>>b;
	switch(b){
		case 1:customer();run1();break;
		case 2:setorder();run1();break;
		case 3:delorder();run1();break;
		case 4:seaorder();run1();break;
		case 5:system("pause");
               cout<<"�����������......"<<endl;
		       system("CLS"); 
			   run();
			   break; 
	}
}
//�˿�ѡ��
void Control::customer(){
	Order::ordernumber++;
	int amount,id,c,price,num,discount;
	string name; 
	cout<<"���or�ڵ�����-------��1.���  2.�ڵ����ѣ�"<<endl;
	cin>>c;
	if(c==1){ 
		string time,place;
		int phone,fee;
		cout<<"�������ʹ�ʱ��  �ص�  ��ϵ��ʽ  ���ͷ���"<<endl;
		cin>>time>>place>>phone>>fee;
		TakeoutOrder takeoutorder(time,place,phone,fee);
		cout<<"������Ҫ�㼸�ݲ�"<<endl;
		cin>>amount;
		for(int i=1;i<=amount;i++){
			cout<<"���������  �۸�  ���� �ۿ�"<<endl;
			cin>>name>>price>>num>>discount;
			takeoutorder.add_food(name,price,num,discount);
		}
		Order* p=new TakeoutOrder(takeoutorder);
		p->n=Order::ordernumber;
		manager.add_order(p); 
	} 
	if(c==2){
		int tablenum,roomfee;
		cout<<"����������źͰ����"<<endl;
		cin>>tablenum>>roomfee;
		InsideOrder insideorder(tablenum,roomfee);
		cout<<"������Ҫ�㼸�ݲ�"<<endl;
		cin>>amount;
		for(int i=1;i<=amount;i++){
			cout<<"���������  �۸�  ���� �ۿ�"<<endl;
			cin>>name>>price>>num>>discount;
			insideorder.add_food(name,price,num,discount);
		}
		Order* p=new InsideOrder(insideorder);	
		p->n=Order::ordernumber;
		manager.add_order(p);
	}
} 
//�޸Ķ��� 
void Control::setorder(){
	int number,price;
	string name; 
	cout<<"������Ҫ�޸ĵĶ������  ����  �۸�"<<endl;
 	cin>>number>>name>>price;
  	manager.set_order(number,name,price);
}
//ɾ������
void Control::delorder(){
	int number;
	cout<<"������Ҫɾ���Ķ�����"<<endl;
	cin>>number;
	manager.del_order(number);
} 
//���Ҷ���
void Control::seaorder() {
	int number;
	cout<<"������Ҫ���ҵĶ�����"<<endl;
	cin>>number;
	manager.search_order(number);
}