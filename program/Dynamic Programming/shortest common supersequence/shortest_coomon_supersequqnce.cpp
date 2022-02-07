#include<bits/stdc++.h>
using namespace std;

int dp1[100][100];
int dp2[100][100];
int recur_SCS(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)return m+n;
	else if(s1[m-1]==s2[n-1])
			return recur_SCS(s1,s2,m-1,n-1)+1;
	else return min(recur_SCS(s1,s2,m,n-1)+1,recur_SCS(s1,s2,m-1,n)+1);
}

//dynamic
int top_scs(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)return m+n;

	if(dp1[m][n]==0)
	{
		if(s1[m-1]==s2[n-1])
			dp1[m][n] = recur_SCS(s1,s2,m-1,n-1)+1;
	else dp1[m][n] = min(recur_SCS(s1,s2,m,n-1)+1,recur_SCS(s1,s2,m-1,n)+1);	
	}
	return dp1[m][n];
}

//bottom
int bottom_scs(string s1,string s2,int m,int n)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				dp2[i][j]=i+j;
			else if(s1[i-1]==s2[j-1])
				dp2[i][j]=dp2[i-1][j-1]+1;
			else dp2[i][j]=min(dp2[i][j-1],dp2[i-1][j])+1;
		}
	}
	return dp2[m][n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.size(),n=s2.size();
	
	cout<<recur_SCS(s1,s2,m,n)<<endl;
	
	//dynamic
		cout<<top_scs(s1,s2,m,n)<<endl;
		cout<<bottom_scs(s1,s2,m,n)<<endl;
}
