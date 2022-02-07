#include<bits/stdc++.h>
using namespace std;
int n;
int bit[1000000];
void update(int i,int val)
{
	cout<<"a"<<endl;
	for(;i<=n;i+=(i&-i))
			bit[i]+=val;
	cout<<"a"<<endl;
	return;
}
long long int querry(int i)
{
	long long ans=0;
	for(;i>0;i-=(i&-i))
		ans+=bit[i];
	return ans;
} 
int main()
{
	
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		update(i+1,a[i]);
	}
	int c=1;
	while(c)
	{
		cin>>c;
		if(c==0)break;
		else if(c==1)
		{
			int i,val;
			cin>>i>>val;
			update(i+1,val-a[i]);
		}
		else
		{
			int i,j;
			cin>>i>>j;
			cout<<querry(j+1)-querry(i)<<endl;
		}
	}
	return 0;
}


