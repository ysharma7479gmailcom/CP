#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int longest_common_substring(string s1,string s2)
{
	for(int i=0;i<s1.size()+1;i++)
	{
		for(int j=0;j<s2.size();j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=0;
				
			}
	}
	int m=0;
	for(int i=0;i<s1.size()+1;i++)
	{
		for(int j=0;j<s2.size();j++)
			{
			m=max(m,dp[i][j]);
				
			}
	}
	return m;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<longest_common_substring(s1,s2)<<endl;
}
