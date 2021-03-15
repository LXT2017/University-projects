#include"Order.h"
int Order::ordernumber=0;
void Order::add_food(string name,int price,int num,int discount){
	food.name=name;
	food.price=price;
	food.num=num;
	food.discount=discount;
	foodlist.push_back(food);
}
void Order::display(){
	int money=0,dismoney=0;
	vector<Food>::iterator it;
	for(it=foodlist.begin();it!=foodlist.end();it++){
		cout<<(*it).name<<"\t"<<(*it).price<<"\t"<<(*it).num<<"\t"<<(*it).discount<<endl;
		money+=(*it).price;
		dismoney+=(*it).price*(*it).discount/10;
	}
		cout<<"                          Ӧ��:"<<money<<endl;
		cout<<"                          ʵ��:"<<dismoney<<endl;;
}

TakeoutOrder::TakeoutOrder(string time,string place,int phone,int fee){
	this->time=time;
	this->place=place;
	this->phone=phone;
	this->fee=fee;
}
void TakeoutOrder::display(){
	int money; 
	cout<<"ʱ��\t"<<"�ص�\t"<<"�绰\t"<<"С��\n";
	cout<<time<<"\t"<<place<<"\t"<<phone<<"\t"<<fee<<endl<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"����\t"<<"�۸�\t"<<"����\t"<<"�ۿ�\n";
	Order::display();
	cout<<"------------------------------------"<<endl;
}

InsideOrder::InsideOrder(int tablenum,int roomfee){
	this->tablenum=tablenum;
	this->roomfee=roomfee;
}
void InsideOrder::display(){
	cout<<"����\t"<<"�۸�\t"<<"����\t"<<"�ۿ�\n";
	Order::display();
	cout<<"������\t"<<"�����\n";
	cout<<tablenum<<"\t"<<roomfee<<endl;
}

void OrderManager::add_order(Order* order){
	if(order==NULL)
		return ;
	else
		Ordernumber.push_back(order);
}

void OrderManager::search_order(int number){
	for(it=Ordernumber.begin();it!=Ordernumber.end();it++){
		if(((*it)->n)==number){
			cout<<"         ������:"<<number<<endl;
			(*it)->display();
		}
	}
}

void OrderManager::del_order(int number){
	for(it=Ordernumber.begin();it!=Ordernumber.end();it++){
		if(((*it)->n)==number){
			delete (*it);
			break;
	    }
	}
	
}

void OrderManager::set_order(int number,string name,int price){
	for(it=Ordernumber.begin();it!=Ordernumber.end();it++){
		if(((*it)->n)==number){
			((*it)->food).name=name;
			((*it)->food).price=price;
			break;
		}
	}
}
OrderManager::~OrderManager(){
	ofstream on(time.getcurrent(),ios::app);
	for(it=Ordernumber.begin();it!=Ordernumber.end();it++){
		vector<Food> foodlist;
		vector<Food> ::iterator it;
		for(it=foodlist.begin();it!=foodlist.end();it++){
				vector<Food>::iterator it;
				on<<(*it).name<<"\t"<<(*it).price<<"\t"<<(*it).num<<"\t"<<(*it).discount<<endl; 
			}
		if(typeid(*it)==typeid(TakeoutOrder)){
			TakeoutOrder *(*it)=static_cast<TakeoutOrder*>(*it);
			on<<(*it)->time<<"\t"<<(*it)->place<<"\t"<<(*it)->phone<<"\t"<<(*it)->fee<<endl;
		}
		else{
			InsideOrder *(*it)=static_cast<InsideOrder*>(*it);
			on<<(*it)->tablenum<<"\t"<<(*it)->roomfee<<endl;
		}
	}
	on.close();
}
















