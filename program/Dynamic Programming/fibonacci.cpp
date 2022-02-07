//fibonacci

#include<iostream>
using namespace std;

int main()
{
	unsigned long long int a[100];
	a[0]=1;
	a[1]=1;
	
	for(int i=2;i<100;i++)
		{
			a[i]=a[i-2]+a[i-1];
		}
	
	for(int i=0;i<100;i++)
		{
			cout<<a[i]<<" ";
		}
}
