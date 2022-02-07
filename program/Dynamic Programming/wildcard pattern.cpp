#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int wildcard(string s,string p,int n,int m)
{
	if(m<0 && n<0 )
		return 1;
	if(m<0)
		return false;
	if(n<0)
	{
		for(int i=0;i<=m;i++)
				if(p[i]!='*')
				return 0;
	return 1;
	}
	
	if(dp[m][n]==-1)
	{
		if(p[m]=='*')
			dp[m][n]=wildcard(s,p,n-1,m) || wildcard(s,p,n,m-1);
		else if(p[m]!='?' && p[m]!=s[n])
			dp[m][n]=0;
		else dp[m][n]=wildcard(s,p,n-1,m-1);
	}
	return dp[m][n];
}

bool dyna(string s,string p)
{
	bool t[s.size()+1][p.size()+1];
	
	cout<<t[0][0]<<" "<<t[0][1]<<endl;
	t[0][0]=true;
	for(int i=1;i<=p.size();i++)
		if(p[i-1]=='*')
			t[0][i]=t[0][i-1];
	
	for(int i=1;i<s.size()+1;i++)
	{
		for(int j=1;j<p.size()+1;j++)
		{
			 if(p[j-1]=='*')
					t[i][j]=t[i-1][j] || t[i][j-1];
			
			else if(p[j-1]=='?' || p[j-1]==s[i-1])
				 t[i][j]=t[i-1][j-1];
		
		}
	}
	return t[s.size()][p.size()];
}

int main()
{
	string s,p;
	cin>>s>>p;
	
	memset(dp,-1,sizeof(dp));
	cout<<wildcard(s,p,s.size()-1,p.size()-1)<<endl;
	
	
	cout<<dyna(s,p);
}
