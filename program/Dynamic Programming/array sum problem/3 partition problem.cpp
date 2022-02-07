#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
bool coin(int *a,int n,int x,int y,int z)
{
	if(x==0 && y==0 && z==0)return true;
	if(n==0)return false;
	if(x<0 || y<0 || z<0)
			return false;
	
	return  coin(a,n-1,x-a[n-1],y,z) || coin(a,n-1,x,y-a[n-1],z) || coin(a,n-1,x,y,z-a[n-1]);
}

int dynamic(int *a,int n,int x,int y,int z)
{
	if(x==0 && y==0 && z==0)return true;
	if(n==0)return false;
	if(x<0 || y<0 || z<0)
			return false;
	string key = char(n) ;
	key=key + char(x) ;
	key=key + char(y) ;
	key=key + char(z);
	if(m[key]==0)
	{
		m[key]=dynamic(a,n-1,x-a[n-1],y,z) || dynamic(a,n-1,x,y-a[n-1],z) || dynamic(a,n-1,x,y,z-a[n-1]);
	}
	return m[key];
}
int main()
{
	int n,s=0;
	cin>>n;
	int *a=new int[n];
	
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	s=s+a[i];
	}
	
	if(s%3!=0)
		cout<<"N0"<<endl;
	else
		{
			bool c=coin(a,n,s/3,s/3,s/3);
			
			if(c)cout<<"YES";
			else cout<<"NO";
			cout<<endl;
			c=dynamic(a,n,s/3,s/3,s/3)
			if(c)cout<<"YES";
			else cout<<"NO";	
		}	
	
	
	
}
