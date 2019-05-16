#include <bits/stdc++.h>
using namespace std;

class Order
{
private: 
	map<int, string>mp;
public:
	/*Order();
	~Order();*/
	void setOrder(int order_id, string pname)
	{
		//if(mp[order_id])
		mp[order_id]=pname;
	}
	void getOrderDetail(int id)
	{
		if(mp.find(id)!= mp.end())
			cout<<endl<<"ID "<<id<<" Product Name is "<< mp[id]<<endl<<endl;
	}
};

int main()
{
	int ch,order_id=0,id;
	Order od;
	while(1)
	{
		cout<<"1. Insert order\n2. Get order details by ID\n3. Exit\nEnter your choice : ";
		cin>>ch;
		string name;
		switch(ch)
		{
			case 1: cout<<"Enter the product name : ";
					cin>>name;
					order_id++;
					od.setOrder(order_id,name);
					break;
			case 2: cout<<"Ente order id which is less than "<<order_id<<" : ";
					cin>>id;
					if(id>0 && id <= order_id)
						od.getOrderDetail(id);
					else
						cout<<"ID not exist"<<endl<<endl;
					break;
			case 3: exit(1);
		}
	}
	return 0;
}