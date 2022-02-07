#include<bits/stdc++.h>
using namespace std;

int rec(int dp[],int m)
{
	stack<int> s;
	int ma=0,area=0,curr=0,i=0;
	
	while(i<m)
	{
		if(s.empty() || dp[i]>=dp[s.top()])
			{
				s.push(i);
				i++;
			}
		else
		{
			curr=s.top();
			s.pop();
			if(s.empty())
				area=i*dp[curr];
			else
				area=dp[curr]*(i-1-s.top());
			
			ma=max(area,ma);
		}
	}
	
	while(!s.empty())
	{
		curr=s.top();
			s.pop();
			if(s.empty())
				area=i*dp[curr];
			else
				area=dp[curr]*(i-1-s.top());
			
			ma=max(area,ma);
	}
	
	return ma;
}

int maximum(char **matrix,int n,int m)
{
	int dp[m]={0};
	int s=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]=='1')
				dp[j]=dp[j]+1;
			else dp[j]=0;
		}
		s=max(s,rec(dp,m));
	}
	return s;
}
int main()
{
	int n, m;
	cin>>n>>m;
	
	char **matrix=new char*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new char[m];
		for(int j=0;j<m;j++)
			{
				cin>>matrix[i][j];
			}
	}
	
	cout<<maximum(matrix,n,m);
}


