by6#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

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
		t pop();
		t distop();
		void enhancecap();
		int isempty();
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
int stack<t>::isempty()
{
	if(top<0)
		return 1;
	else
		return 0;
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
t stack<t>::pop()
{
	t x;
	if(top<0)
	{
		return 0;
	}
	else
	{
		x=stk[top--];
		return x;
	}
}

template<class t>
t stack<t>::distop()
{
	if(top<0)
	{
		return 0;
	}
	else
	{
		return stk[top];
	}
}

int priority(char ch)
{
	switch(ch)
	{
		case '^': return 5;
		case '*':
		case '/':
		case '%': return 4;
		case '+':
		case '-': return 3;
		case '(': return 2;
		case ')': return 1;
	}
	return 0;
}

void convert(char *a)
{
	int i,x,j=0;
	stack<char> st(20);
	char b[20];
	int len=strlen(a);
	for(i=0;i<len;i++)
	{
		char ch=a[i];
		if(isalpha(ch))
			b[j++]=ch;
		else if(isdigit(ch))
			b[j++]=ch;
		else if(ch=='(')
			st.push(ch);
		else if(ch==')')
		{
			while(st.distop()!='(')
				b[j++]=st.pop();
			st.pop();
		}
		else
		{
			while(priority(ch)<=priority(st.distop()))
			{
				b[j++]=st.pop();
			}
			st.push(ch);
		}
	}
	while(!st.isempty())
		b[j++]=st.pop();
	b[j]='\0';

	cout<<"Postfix Expression is "<<endl;
	cout<<b;
}

void main()
{
	char a[20];
	clrscr();
	cout<<"Enter an infix expression"<<endl;
	cin>>a;
	convert(a);
	getch();
}







