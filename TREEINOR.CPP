#include<iostream>
#include<conio.h>
using namespace std;

template<class t>
class tree;

template<class t>
class stack
{
	private:
		t *stk;
		int top,cap;
	public:
		stack()
		{
			cap=10;
			stk=new t[cap];
			top=-1;
		}
		void push(t x);
		t pop();
		t topval();
		void enhancecap();
		int isempty();
		friend class tree<t>;
};

template<class t>
t stack<t>::topval()
{
    return stk[top];

}

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
t stack<t>::pop()
{
	t x;
	if(top<0)
	{
		return isempty();
	}
	else
	{
		x=stk[top--];
		return x;
	}
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
class treenode
{
	friend class tree<t>;
	treenode<t> *leftchild;
	treenode<t> *rightchild;
	t data;
};

template<class t>
class tree
{
	private:
		treenode<t> *currentnode;
		treenode<t> *root;
	public:
		tree()
		{
			root=NULL;
		}

		void inorder();
		void create();
		void insert();
		void erase();

};

template<class t>
void tree<t>::inorder()
{
	stack<treenode<t>*> s;
	treenode<t> *currentnode=root;
	while(1)
	{
		while(currentnode)
		{
			s.push(currentnode);
			currentnode=currentnode->leftchild;
		}

		if(s.isempty())
			exit;

		currentnode=s.topval();
		s.pop();
		visit(currentnode);
		currentnode=currentnode->rightchild;
	}
}

int main()
{

	tree<int> tr;
    tr.create();
    tr.inorder();
	getch();

}
