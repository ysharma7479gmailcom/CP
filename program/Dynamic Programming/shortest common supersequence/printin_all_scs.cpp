#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

vector<string> print_all_scs(string s1,string s2,int m,int n)
{
	if(m==0)
	{
		vector<string> v;
		v.push_back(s2.substr(0,n));
		return v;
	}
	if(n==0)
	{
		vector<string> v;
		v.push_back(s1.substr(0,m));
		return v;
	}
	
	if(s1[m-1]==s2[n-1])
	{
		vector<string> scs=print_all_scs(s1,s2,m-1,n-1);
		for(int i=0;i<scs.size();i++)
			scs[i].push_back(s1[m-1]);
		return scs;
	}
	
	else 
	{
		if(dp[m-1][n]<dp[m][n-1])
			{
				vector<string> scs=print_all_scs(s1,s2,m-1,n);
				for(int i=0;i<scs.size();i++)
			scs[i].push_back(s1[m-1]);
		return scs;
			}
		
		if(dp[m-1][n]>dp[m][n-1])
			{
				vector<string> scs=print_all_scs(s1,s2,m,n-1);
				for(int i=0;i<scs.size();i++)
			scs[i].push_back(s2[n-1]);
		return scs;
			}
		
		vector<string> top=print_all_scs(s1,s2,m-1,n);
			for(int i=0;i<top.size();i++)
			top[i].push_back(s1[m-1]);
			
		vector<string> left=print_all_scs(s1,s2,m,n-1);
				for(int i=0;i<left.size();i++)
			left[i].push_back(s1[m-1]);
		
		top.insert(top.end(),left.begin(),left.end());
		return top;
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
	vector<string> scs1=print_all_scs(s1,s2,m,n);
	map<string,int> scs2;
	
//for (auto it=scs2.begin(); it != scs2.end();it++) 
//        cout <<endl << *it;
	

	for(int i=0;i<scs1.size();i++)
	if(scs2[scs1[i]]==0)
	{
		scs2[scs1[i]]=1;
		cout<<scs1[i]<<endl;
	}
		
	
	
}
