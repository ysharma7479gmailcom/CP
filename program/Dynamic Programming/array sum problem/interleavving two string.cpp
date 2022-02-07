#include<bits/stdc++.h>
using namespace std;
bool dp[100][100][100];
bool recur_interleaving_string(string x,string y,string z,int n,int m,int o)
{
	if(n==0 && m==0 && o==0)return true;
	if(o<0)return false;
	
	bool a,b;
	if( n>0 && z[o-1]==x[n-1])
		a=recur_interleaving_string(x,y,z,n-1,m,o-1);
	if(m>0 && z[o-1]==y[m-1])
		b=recur_interleaving_string(x,y,z,n,m-1,o-1);
	return a||b;
}

bool dynamic(string x,string y,string z,int n,int m,int o)
{
	if(n==0 && m==0 && o==0)return true;
	if(o<0)return false;
		
		if(dp[m][n][o]==0)
		{
			bool a=false,b=false;
	if( n>0 && z[o-1]==x[n-1])
		a=dynamic(x,y,z,n-1,m,o-1);
	if(m>0 && z[o-1]==y[m-1])
		b=dynamic(x,y,z,n,m-1,o-1);
		
			if(a||b)
			dp[m][n][o]=-1;
		else dp[m][n][o] = a||b;
		}
	return dp[m][n][o];	
}
int main()
{
	string x,y,z;
	cin>>x>>y>>z;
	
	int n=x.size();
	int m=y.size();
	int o=z.size();
	
	if(o==n+m)
	{
		cout<<recur_interleaving_string(x,y,z,n,m,o)<<endl;
		cout<<dynamic(x,y,z,n,m,o)<<"sd"<<endl;
	}
	else cout<<"N_o";
}
