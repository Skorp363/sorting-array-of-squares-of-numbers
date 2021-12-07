#include <iostream>
#include <cmath>
#include <cstdlib>

#include <time.h>
#define MAXARRAY 10
using namespace std;
void mergesort(int a[],int low, int high);
int main(void)
{
	srand(time(NULL));
	int n,i;
	int m[MAXARRAY];
	
	for (i=0;i<MAXARRAY;i++)
	{
		cin>>m[i];
		
	}
	cout<<"Before sorting: ";
	for (i=0;i<MAXARRAY;i++)
	  {
		cout<<m[i]<<" ";
	   m[i]=m[i]*m[i];}
	   cout<<endl;
	mergesort(m,0,(MAXARRAY-1));
	cout<<"After sorting: ";
	for (i=0;i<MAXARRAY;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;
	system ("pause");
	return 0;
}
void mergesort(int a[],int low,int high)
{
	int i=0;
	int length = high - low + 1;
	int pivot =0;
	int merge1=0;
	int merge2 =0;
	int working[length];
	
	if(low==high)
	 return;
	
	pivot = (low+high)/2;
	mergesort(a,low,pivot);
	mergesort(a,pivot+1,high);
	
	for (i=0;i<length;i++)
	 working[i]=a[low+i];
	
	merge1=0;
	merge2=pivot-low+1;
	
	for (i=0;i<length;i++)
	{
		if (merge2<=high-low)
		 if(merge1<=pivot-low)
		  if (working[merge1]>working[merge2])
			a[i+low]=working[merge2++];
		  else
		  a[i+low]=working[merge1++];
		 else
		 a[i+low]=working[merge2++];
		else
		a[i+low]=working[merge1++];
	}
}
