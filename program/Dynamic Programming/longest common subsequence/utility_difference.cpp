#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
string ans[100][100]; 
void diff_utility(string s1,string s2,int m,int n)
{
	
	if(m>0 && n>0 && s1[m-1]==s2[n-1])
	{
		diff_utility(s1,s2,m-1,n-1);
		cout<<" "<<s1[m-1];
	}
	
	// current character present in s2 not in s1
	
	else if(n>0 && (m==0 || dp[m][n-1]>=dp[m-1][n]))
	{
		diff_utility(s1,s2,m,n-1);
		cout<<" +"<<s2[n-1];
	}
	
		// current character present in s1 not in s2
	
	else if(m>0 && (n==0 || dp[m][n-1]<dp[m-1][n]))
	{
		diff_utility(s1,s2,m-1,n);
		cout<<" -"<<s1[m-1];
	}
}

//dynamic doubt
string top(string s1,string s2,int m,int n)
{
	if(ans[m][n].size()==0)
	{
		if(m>0 && n>0 && s1[m-1]==s2[n-1])
		ans[m][n]=top(s1,s2,m-1,n-1)+" "+ s1[m-1];
		else if(n>0 && (m==0 || dp[m][n-1]>=dp[m-1][n]))
			ans[m][n]= " +"+s2[n-1];
		else if(m>0 && (n==0 || dp[m][n-1] < dp[m-1][n]))
			ans[m][n]=" -"+s1[m-1];
	}
	return ans[m][n];
}
void lcs(string s1,string s2,int m,int n)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(s1[i-1]==s2[j-1])
						dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	lcs(s1,s2,s1.size(),s2.size());
	top(s1,s2,s1.size(),s2.size());
	cout<<ans[s1.size()][s2.size()];
	cout<<endl;
	diff_utility(s1,s2,s1.size(),s2.size());
}
