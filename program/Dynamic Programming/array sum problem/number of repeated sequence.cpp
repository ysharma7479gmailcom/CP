#include<bits/stdc++.h>
using namespace std;
int ans=0;
int dp[100][100];
void repeated_sequence(string s1,string s2,int n,int m)
{
	if(m==0)
	{
		ans++;
		return;
	}
	if(n==0)return;
	
	if(s1[n-1]==s2[m-1])
		repeated_sequence(s1,s2,n-1,m-1);

		repeated_sequence(s1,s2,n-1,m);
	return;
}

int dynamic(string s1,string s2,int n,int m)
{
	if(m==0)
		return 1;
	if(n==0)return 0;
	
	if(dp[n][m]==0)
	{
		if(s1[n-1]==s2[m-1])
		dp[n][m]=dynamic(s1,s2,n-1,m-1);
		
		dp[n][m]=dp[n][m]+dynamic(s1,s2,n-1,m);
	}
	return dp[n][m];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	repeated_sequence(s1,s2,s1.size(),s2.size());
	cout<<ans<<endl;
	cout<<dynamic(s1,s2,s1.size(),s2.size());
}

5
1 1 -1 1 1
1 0 0 -1 1
1 1 1 1 -1
-1 -1 1 1 1
1 1 -1 -1 1
