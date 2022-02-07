#include<bits/stdc++.h>
#include<math.h>

using namespace std;

bool sign(int n)
{
	return n>0;
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		long long r=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			r+=a[i];
		}
		cout<<r<<endl;
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		int j=i;
		int ma=a[i];
		while(j<n && sign(a[i])==sign(a[j]))
			ma=max(ma,a[j]),j++;
		i=j-1;
		ans=ans+ma;
		cout<<ans<<endl;
		
	}
		
		cout<<ans<<endl;
		
	}
}
