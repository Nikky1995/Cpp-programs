#include<iostream>
#include<conio.h>
using namespace std;
class search
{
	private:
		int *a,n,key;
	public:
		void accept();
		void bsort();
		void binary()
		{
			int flag;
			cout<<"Enter the element to be searched:"<<endl;
			cin>>key;
			flag=binsearch(a,key,0,n);
			if(flag==0)
			{
				cout<<"Data not found!!!"<<endl;
			}
		}
		int binsearch(int *a,int key,int low,int high);
};
void search::accept()
{
			int i;
			cout<<"Enter the size of the array:"<<endl;
			cin>>n;
			a=new int[n];
			cout<<"Enter the elements into the array:"<<endl;
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
}
int main()
{

	search data;
	data.accept();
	data.bsort();
	data.binary();
	getch();
}

void search::bsort()
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
	cout<<"The data you entered is:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int search::binsearch(int *a,int key,int low, int high)
{
	if(low<=high)
	{
	int mid=(low+high)/2;
	if(key==a[mid])
	{
		cout<<key<<" found at "<<mid+1<<endl;
		return 1;
	}
	if(key<a[mid])
		return binsearch(a,key,low,mid-1);
	if(key>a[mid])
		return binsearch(a,key,mid+1,high);
	}
	else
	{
		return 0;
	}
}
