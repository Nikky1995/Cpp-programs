#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

template<class t>
class cqueue
{
	private:
		int maxsize;
		int front,rear;
		t *cque;
	public:
		cqueue(int size)
		{
			maxsize=size;
			cque=new t[maxsize];
			front=-1;
			rear=-1;
		}
		void disfront();
		void disrear();
		void empty();
		void push(t x);
		void pop();
		void display();
		void enhancecap();

};

template<class t>
void cqueue<t>::push(t x)
{
	if(front==(rear+1)%maxsize)
	{
		cout<<"Circular Queue is full!! Capacity is enhanced"<<endl;
		enhancecap();
	}

		rear=(rear+1)%maxsize;
		cque[rear]=x;
		if(front==-1)
			front=0;


}

template<class t>
void cqueue<t>::enhancecap()
{
	int i,j,last;
	last=maxsize-1;
	maxsize*=2;
	t *temp=new t[maxsize];

	j=0;
	if(front>rear)
	{
		for(i=front;i<=last;i++)
		{
			temp[j]=cque[i];
			j++;
		}
		for(i=0;i<=rear;i++)
		{
			temp[j]=cque[i];
			j++;
		}
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			temp[j]=cque[i];
			j++;
		}
	}
	front=0;
	rear=j-1;

	delete[] cque;
	cque=temp;

}

template<class t>
void cqueue<t>::pop()
{
	t x;
	if(front==-1)
	{
		cout<<"Circular Queue is empty!!"<<endl;
	}
	else
	{
		x=cque[front];
		cout<<"The element deleted is "<<x<<endl;

		if(front==rear)
		{
			front=-1;
			rear=-1;
		}

		else
			front=(front+1)%maxsize;
	}

}

template<class t>
void cqueue<t>::display()
{
	int i;
	if(front==-1)
	{
		empty();
	}
	else
	{
		cout<<"The elements in the circular queue are:"<<endl;
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			cout<<cque[i]<<endl;
		}
		else
		{
			for(i=front;i<=maxsize-1;i++)
				cout<<cque[i]<<endl;
			for(i=0;i<=rear;i++)
				cout<<cque[i]<<endl;
		}
	  }
}

template<class t>
void cqueue<t>::empty()
{
	if(front==-1)
		cout<<"Circular Queue is empty"<<endl;

}

template<class t>
void cqueue<t>::disfront()
{
	if(front!=-1)
		cout<<"Front element in the queue is  "<<cque[front]<<endl;
	else
		cout<<"The queue is empty"<<endl;
}

template<class t>
void cqueue<t>::disrear()
{
	if(rear!=-1)
		cout<<"Rear element in the queue is "<<cque[rear]<<endl;
	else
		cout<<"The queue is empty"<<endl;
}

int main()
{
	int size,option;
	int ele;

	cout<<"CIRCULAR QUEUES"<<endl;
	cout<<"Enter the size of the circular queues:"<<endl;
	cin>>size;
	cqueue<int> cq(size);

	do
	{
		cout<<"1.Push an element into the Circular Queue"<<endl;
		cout<<"2.Delete the Front element from the Circular Queue"<<endl;
		cout<<"3.Display Elements of the Circular Queue"<<endl;
		cout<<"4.Display Front element of the Circular Queue"<<endl;
		cout<<"5.Display Rear element of the Circular Queue"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter your option:"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"Enter the element to be pushed:"<<endl;
				cin>>ele;
				cq.push(ele);
				break;
			case 2:
				cq.pop();
				break;
			case 3:
				cq.display();
				break;
			case 4:
				cq.disfront();
				break;
			case 5:
				cq.disrear();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Invalid Option!!\tTry again.."<<endl;
		}
	}while(option!=6);
	getch();
}
