#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n,0);
	
	for(int i=0;i<n;i++)
		cin>>v[i];
	long long int res=INT_MIN;
	long int a=INT_MIN,b=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(v[i]>a)
		{
			b=a;
			a=v[i];
		}
		else if(v[i]>b)b=v[i];
	}

	res=(long long)a*b;
	cout<<res;
	
	return 0;
}
