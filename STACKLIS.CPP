#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
template<class t>
class node
{
	private:
		t data;
		node<t> *link;
		friend lstack<t>;
};

template<class t>
class lstack
{
	private:
		node<t> *top;
	public:
		lstack()
		{
			top=NULL;
		}
		void push(t x);
		t pop();
		void display();

};

template<class t>
void lstack<t>::push(t x)
{
	node<t> *nnode=new node<t>;
	nnode->data=x;
	if(top==NULL)
	{
		nnode->link=NULL;
		top=nnode;
	}
	else
	{
		nnode->link=top;
		top=nnode;
	}
}

template<class t>
t lstack<t>::pop()
{
	t x;
	if(top!=NULL)
	{
		node<t> *temp=top;
		top=temp->link;
		x=temp->data;
		delete temp;
		return x;
	}
	else
		return 0;
}

template<class t>
void lstack<t>::display()
{
	node<t> *temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->link;
	}
}

void main()
{
	lstack<int> ls;
	int choice;
	int val;
	clrscr();
	do
	{
		cout<<"Linked Stack"<<endl;
		cout<<"1.Push 2.Pop 3.Display 4.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the value:";
				cin>>val;
				ls.push(val);
				break;
			case 2:
				val=ls.pop();
				cout<<"The value deleted is "<<val<<endl;
				break;
			case 3:
				cout<<"The elements of linked stack are:"<<endl;
				ls.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Not a valid option"<<endl;
		}
	}while(choice!=4);
	getch();
}








