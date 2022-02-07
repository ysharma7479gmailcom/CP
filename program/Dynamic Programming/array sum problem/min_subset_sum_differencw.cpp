#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int min_sum(int *a,int n,int s1,int s2)
{
	
	if(n<1)return abs(s1-s2);
		
	int x=min_sum(a,n-1,s1+a[n-1],s2);
	int y=min_sum(a,n-1,s1,s2+a[n-1]);
	return min(x,y);
	
}

int dynamic(int *a,int n,int s1,int s2)
{
	if(n<1)return abs(s1-s2);
	
	string key=char(n+48) + "|" + char(s1+48);
	if(m[key]==0)
	{
		int x=dynamic(a,n-1,s1+a[n-1],s2);
		int y=dynamic(a,n-1,s1,s2+a[n-1]);
		
		m[key]=min(x,y);
	}
	return m[key];
}

int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//coin change type
	cout<<min_sum(a,n,0,0)<<endl;
	
	cout<<dynamic(a,n,0,0)<<endl;
}
