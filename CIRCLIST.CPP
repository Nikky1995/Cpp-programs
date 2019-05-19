#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

template<class t>
class node
{
	t data;
	node<t> *link;
	friend cirlist<t>;
}

template<class t>
class cirlist
{
	private:
		node<t> *first;
	public:
		void insert(t x,int k);
		void deleten(int k);
		void display();
		cirlist()
		{
			first=NULL;

		}
};

template<class t>
void cirlist<t>::insert(t x,int k)
{
	node<t> *nnode=new node<t>;
	node<t> *temp=first;
	nnode->data=x;
	if(k==1)
	{
		if(first==NULL)
		{
			nnode->link=nnode;
			first=nnode;
		}
		else
		{
			while(temp->link!=first)
			{
				temp=temp->link;
			}
			nnode->link=first;
			first=nnode;
			temp->link=first;
		}
	}
	else
	{
		for(int i=1;i<k-1&&temp->link!=first;i++)
			temp=temp->link;
		nnode->link=temp->link;
		temp->link=nnode;
	}

}

template<class t>
void cirlist<t>::deleten(int k)
{
	node<t> *dnode=NULL;
	node<t> *temp=first;
	if(first!=NULL)
	{
		if(k==1)
		{
			dnode=first;
			while(temp->link!=first)
				temp=  temp->link;
			if(first==dnode->link)
				first=NULL;
			else
				first=dnode->link;
			temp->link=first;
			delete dnode;
		}
		else
		{
			for(int i=1;i<k-1&&temp->link!=first;i++)
				temp=temp->link;
			dnode=temp->link;
			temp->link=dnode->link;
			delete dnode;
		}
	}
	else
	{
		cout<<"List is empty"<<endl;
	}
}

template<class t>
void cirlist<t>::display()
{
	node<t> *temp=first;
	while(1)
	{
		cout<<temp->data<<endl;
		if(temp->link==first)
			break;
		temp=temp->link;
	}

}

void main()
{
	cirlist<int> cl;
	int option,k;
	int val;
	clrscr();
	do
	{
		cout<<"Circular List"<<endl;
		cout<<"1.Insert 2.Delete 3.Display 4.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"Enter the value and position:";
				cin>>val>>k;
				cl.insert(val,k);
				break;
			case 2:
				cout<<"Enter the position:";
				cin>>k;
				cl.deleten(k);
				cout<<"The node is deleted"<<endl;
				break;
			case 3:
				cout<<"The elements of circular list are:"<<endl;
				cl.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Not a valid option"<<endl;
		}
	}while(option!=4);
	getch();
}