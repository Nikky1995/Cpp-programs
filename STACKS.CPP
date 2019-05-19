#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

template<class t>
class stack
{
	private:
		t *stk;
		int top,cap;
	public:
		stack(int size)
		{
			cap=size;
			stk=new t[cap];
			top=-1;
		}
		void push(t x);
		void pop();
		void distop();
		void enhancecap();
		void display();
		void empty();
};

template<class t>
void stack<t>::push(t x)
{
	if(top==cap-1)
	{
		enhancecap();
	}
	stk[++top]=x;

}

template<class t>
void stack<t>::enhancecap()
{
	cap*=2;
	t *temp=new t[cap];
	for(int i=0;i<=top;i++)
		temp[i]=stk[i];

	delete[] stk;
	stk=temp;
}

template<class t>
void stack<t>::pop()
{
	t x;
	if(top<0)
	{
		empty();
	}
	else
	{
		x=stk[top--];
		cout<<"The element deleted is "<<x<<endl;
	}
}

template<class t>
void stack<t>::distop()
{
	if(top<0)
	{
		empty();
	}
	else
	{
		cout<<"The Top element is "<<stk[top]<<endl;
	}
}

template<class t>
void stack<t>::empty()
{
	if(top<0)
	{
		cout<<"Stack is empty"<<endl;
	}
}

template<class t>
void stack<t>::display()
{
	if(top<0)
		empty();
	else
	{
		cout<<"The Elements of the Stack are:"<<endl;
		for(int i=top;i>=0;i--)
			cout<<stk[i]<<endl;
	}
}



void main()
{
	int size,option;
	int ele;
	clrscr();
	cout<<"STACKS"<<endl;
	cout<<"Enter the size of the stacks"<<endl;
	cin>>size;
	stack<int> s(size);
	do
	{
		cout<<"1.Enter a element into stack"<<endl;
		cout<<"2.Delete the top element"<<endl;
		cout<<"3.Display Top element"<<endl;
		cout<<"4.Display Elements of the Stack"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>option;

		switch(option)
		{
			case 1:
				cout<<"Enter the value to be pushed"<<endl;
				cin>>ele;
				s.push(ele);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.distop();
				break;
			case 4:
				s.display();
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Invalid option!!\tTry Again."<<endl;
		}
	}while(option!=5);
	getch();
}
