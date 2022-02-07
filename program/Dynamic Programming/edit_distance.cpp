#include<bits/stdc++.h>
using namespace std;
int dp1[100][100];
int dp2[100][100];
int recur_edit_distance(string s1,string s2,int m,int n)
{
	if(m==0 || n==0 )
			return m+n;
	if(s1[m-1]==s2[m-1])
		return recur_edit_distance(s1,s2,m-1,n-1);
	else
		{
			return min(recur_edit_distance(s1,s2,m-1,n-1),min(recur_edit_distance(s1,s2,m-1,n),recur_edit_distance(s1,s2,m,n-1)))+1;
		}
}

int top_edit(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)
		return m+n;
	
	if(dp1[m][n]==0)
	{
		if(s1[m-1]==s2[n-1])
			dp1[m][n]=top_edit(s1,s2,m-1,n-1);
		else dp1[m][n]=1+min(top_edit(s1,s2,m-1,n-1),min(top_edit(s1,s2,m-1,n),top_edit(s1,s2,m,n-1)));
	}
	return dp1[m][n];
}

int bottom_edit(string s1,string s2,int m,int n)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
			{
				if(i==0 || j==0)
					dp2[i][j]=i+j;
				else if(s1[i-1]==s2[j-1])
					dp2[i][j]=dp2[i-1][j-1];
				else dp2[i][j]=min(dp2[i-1][j-1],min(dp2[i-1][j],dp2[i][j-1]))+1;
			}
	}
	return dp2[m][n];
}

int space_edit(string s1,string s2,int m,int n)
{
	int curr[n+1]={0},prev[n+1]={0};
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				curr[j]=i+j;
			else if(s1[i-1]==s2[j-1])
				curr[j]=prev[j-1];
				else curr[j]=min(prev[j-1],min(prev[j],curr[j-1]))+1;
		}
		for(int k=0;k<n+1;k++)
			prev[k]=curr[k];
	}
	return curr[n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.size(),n=s2.size();
	
	//recur
	cout<<recur_edit_distance(s1,s2,m,n)<<endl;
	
	//bottom_edit
	cout<<bottom_edit(s1,s2,m,n)<<endl;
	
	//top
	cout<<top_edit(s1,s2,m,n)<<endl;
	
	//spaceoptimised
	
	cout<<space_edit(s1,s2,m,n)<<endl;
}
