#include<iostream>
#include<conio.h>
using namespace std;

template<class t>
class node
{
	private:
		t data;
		node<t> *lchild,*rchild;
		friend class tree<t>;
		friend void preorder(node<t> *);
		friend void postorder(node<t> *);
		friend void inorder(node<t> *);
		friend erase(node<t> *);
};

template<class t>
class tree
{
	private:
		node<t> *root;
	public:
		tree()
		{
			root=NULL;
		}
		void create();
		void insert(node<t> *);
		void traverse();
		friend void preorder(node<t> *);
		friend void postorder(node<t> *);
		friend void inorder(node<t> *);
		friend erase(node<t> *);
};

template<class t>
void tree<t>::create()
{
	node<t> *k;
	t x;
	cout<<"Enter values of node terminated by -1"<<endl;
	cin>>x;
	while(x!=-1)
	{
		k=new node<t>;
		k->data=x;
		k->lchild=k->rchild=NULL;
		insert(k);
		cin>>x;
	}
}

template<class t>
void tree<t>::insert(node<t> *k)
{
	node<t> *p;
	if(root==NULL)
	{
		root=k;
		return;
	}
	else
	{
		p=root;
		while(1)
		{
			if(k->data<p->data)
			{
				if(p->lchild!=NULL)
					p=p->lchild;
				else
				{
					p->lchild=k;
					return;
				}
			}
			else
			if(k->data>p->data)
			{
				if(p->rchild!=NULL)
					p=p->rchild;
				else
				{
					p->rchild=k;
					return;
				}
			}
			else
			{
				cout<<k->data<<" Already existing\n";
				return;
			}
		}
	}
}

template<class t>
void preorder(node<t> *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<"\t";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

template<class t>
void postorder(node<t> *p)
{
	if(p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<"\t";
	}
}

template<class t>
void inorder(node<t> *p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		cout<<p->data<<"\t";
		inorder(p->rchild);
	}
}

template<class t>
void tree<t>::traverse()
{
	int ch;
	cout<<"1.Preorder\t2.Postorder\t3.Inorder\n";
	cout<<"Enter your choice\n";
	cin>>ch;
	while(ch>=1&&ch<=3)
	{
		switch(ch)
		{
			case 1:
				preorder(root);
				cout<<endl;
				break;
			case 2:
				postorder(root);
				cout<<endl;
				break;
			case 3:
				inorder(root);
				cout<<endl;
				break;
		}
		cout<<"1.Preorder\t2.Postorder\t3.Inorder\n";
		cout<<"Enter your choice";
		cin>>ch;
	}
}

template<class t>
void erase(node<t> *p)
{
	if(p->lchild!=NULL)
		erase(p->lchild);
	if(p->rchild!=NULL)
		erase(p->rchild);
	delete p;
}

void main()
{
	clrscr();
	tree<int> s;
	s.create();
	s.traverse();
	getch();
}






