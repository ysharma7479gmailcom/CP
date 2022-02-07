#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

string print_scs(string s1,string s2,int m,int n)
{
	if(m==0)
		return s2.substr(0,n);
	else if(n==0)
		return s1.substr(0,m);
	if(s1[m-1]==s2[n-1])
		return print_scs(s1,s2,m-1,n-1)+s1[m-1];
	else 
	{
		if(dp[m-1][n]<dp[m][n-1])
			return print_scs(s1,s2,m-1,n)+s1[m-1];
		else return print_scs(s1,s2,m,n-1)+s2[n-1];
	}
}

void scslength(string s1,string s2,int m,int n)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=i+j;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
		}
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int m=s1.size(),n=s2.size();
	
	scslength(s1,s2,m,n);
	
	cout<<print_scs(s1,s2,m,n)<<endl<<endl;
}
