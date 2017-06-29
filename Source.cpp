#include<iostream>
using namespace std;
void swap(int *a,int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	return ;
}
void quick(int *a,int left,int right)
{
	int min=0,pivot=0;
	min=(left+right)/2;
	pivot=a[min];
	int i,j;
	i=left;
	j=right;
	while(left<j||i<right)
	{
		while(a[i]<pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<=j)
		{
			swap(a,i,j);
			i++;
			j--;
		}	
		else
		{
			if(left<j)
				quick(a,left,j);
			if(i<right)
				quick(a,i,right);	
			break ;	
		}	
	}
	return ;
}
int main()
{
	int size=0;
	cout<<"Enter Size: "<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter Data: "<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	quick(arr,0,((sizeof(arr)/sizeof(arr[0])-1)));
	cout<<"Sorted Data: "<<endl;
	for(int i=0;i<size;i++)
		cout<<"   "<<arr[i];
	return 1;	
}
