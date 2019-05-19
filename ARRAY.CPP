
 #include<iostream.h>
#include<conio.h>
#include<stdlib.h>
template<class t>
class arraylist
{
	private:
		int maxsize,len;
		t *a;
	public:
		arraylist(int size)
		{
			maxsize=size;
			len=0;
			a=new t[maxsize];
		}
		void insert(int k,t ele);
		void delele(int k);
		void display();
};

template<class t>
void arraylist<t>::insert(int k,t ele)
{
	int i;
	if((k<0)||(k>=maxsize-1))
	{
		cout<<"Index value of element is out of boundary"<<endl;
		exit(0);
	}
	if(len==maxsize)
	{
		cout<<"The array is filled"<<endl;
		exit(0);
	}
	for(i=len-1;i>=k;i--)
	{
		a[i+1]=a[i];
	}
	a[k]=ele;
	len++;
}

template<class t>
void arraylist<t>::delele(int k)
{
	int i;
	t ele;
	if((k<0)||(k>maxsize-1))
	{
		cout<<"Index value is out of boundary"<<endl;
		exit(0);
	}
	if(len<0)
	{
		cout<<"There are no elements left in array"<<endl;
		exit(0);
	}
	ele=a[k];
	cout<<"The element "<<ele<<" is deleted"<<endl;
	for(i=k;i<len;i++)
	{
		a[i]=a[i+1];
	}
	len--;

}
template<class t>
void arraylist<t>::display()
{
	int i;
	for(i=0;i<len;i++)
	{
		cout<<i<<" "<<a[i]<<endl;
	}
}

void main()
{
	int size,ch;
	int k;
	char ele;
	clrscr();
	cout<<"Enter the size of the array"<<endl;
	cin>>size;

	arraylist<char> array(size);
	do
	{
		cout<<"1.Insert an element"<<endl;
		cout<<"2.Delete an element"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;

		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the index and value of element in array"<<endl;
				cin>>k>>ele;
				array.insert(k,ele);
				break;
			case 2:
				cout<<"Enter the index of the element to be deleted"<<endl;
				cin>>k;
				array.delele(k);
				break;
			case 3:
				cout<<"The elements in array are:"<<endl;
				array.display();
				break;
		}
	}while(ch!=4);
	getch();
}
