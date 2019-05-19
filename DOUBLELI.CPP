#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

template<class t>
class chain;

template<class t>
class node
{
	private:
		t data;
		node<t> *llink,*rlink;
		friend chain<t>;
}

template<class t>
class chain
{
	private:
		node<t> *first;
	public:
		chain()
		{
			first=
		}
		void insert(int k,t x);
		void display();
		void deleten(int k);
};

template<class t>
void chain<t>::insert(int k,t x)
{
	node<t> *nnode=new node<t>;
	nnode->data=x;
	if(k==1)
	{
		if(first==NULL)
		{
		      nnode->llink=NULL;
		      nnode->rlink=NULL;
		      first=nnode;
		}
		else
		{
			nnode->rlink=first;
			nnode->llink=NULL;
			first->llink=nnode;
			first=nnode;
		}
	}
	else
	{
		node<t> *temp=first;
		for(int i=1;i<k-1&&temp->rlink;i++)
			temp=temp->rlink;
		if(temp)
		{
			nnode->llink=temp;
			nnode->rlink=temp->rlink;
			temp->rlink=nnode;
			temp=nnode->rlink;
			temp->llink=nnode;
		}
	}
}

template<class t>
void chain<t>::display()
{
	node<t> *temp=first;
	cout<<"The elements of the linked list are:"<<endl;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp=temp->rlink;
	}
}

template<class t>
void chain<t>::deleten(int k)
{
	node<t> *dnode=NULL;
	node<t> *temp=first;
	if(k==1)
	{
		first=temp->rlink;
		first->llink=NULL;
		delete temp;
	}
	else
	{
		for(int i=1;i<k-1&&temp;i++)
			temp=temp->rlink;
		if(temp)
		{
			dnode=temp->rlink;
			temp->rlink=dnode->rlink;
			temp=temp->rlink;
			temp->llink=dnode->llink;
			delete dnode;
		}
		else
			exit(0);
	}
}

void main()
{
	chain<int> ch;
	int k;
	int ele;
	int choice;
	clrscr();
	cout<<"Doubly Linked List"<<endl;
	do
	{
		cout<<"1.Enter Data 2.Delete Data 3.Display Data 4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter position and value:";
				cin>>k;
				cin>>ele;
				ch.insert(k,ele);
				break;
			case 2:
				cout<<"Enter position to delete:";
				cin>>k;
				ch.deleten(k);
				break;
			case 3:
				ch.display();
				break;
			case 4:
				break;
			default:
				cout<<"Try Again"<<endl;
		}
	}while(choice!=4);
	getch();
}




