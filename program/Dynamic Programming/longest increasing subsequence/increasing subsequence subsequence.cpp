#include<bits/stdc++.h>
using namespace std;

int increasing_maxsum(int a[],int n)
{
	vector<int> v(n,0);
	 v[0]=a[0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j] )
			v[i]=max(v[i],v[j]+a[i]);
		}
	}
	int m=0;
	for(int i=0;i<n;i++)
		m=max(m,v[i]);
		
		return m;
}
int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	cout<<increasing_maxsum(a,n)<<endl;
}
