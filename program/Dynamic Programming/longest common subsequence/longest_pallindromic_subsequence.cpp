#include<bits/stdc++.h>
using namespace std;

int dp[100][100]={0};
//recursive
int longest_pallindromic_substr(string s,int i,int j)
{
	
	if(i>j)return 0;
	if(i==j)return 1;
	
	if(s[i]==s[j])
		return longest_pallindromic_substr(s,i+1,j-1)+2;
	else return max(longest_pallindromic_substr(s,i,j-1),longest_pallindromic_substr(s,i+1,j));
}

//dynamic

//top to bottom

int lps_top(string s,int i,int j)
{
		
	if(i>j)return 0;
	
	if(dp[i][j]==0)
	{
		if(i==j)dp[i][j]=1;
	else if(s[i]==s[j])
			dp[i][j]=lps_top(s,i+1,j-1)+2;
	else dp[i][j]=max(lps_top(s,i+1,j),lps_top(s,i,j-1));	
	}
	cout<<i<<"-> "<<j<<" "<<dp[i][j]<<endl;
	return dp[i][j];
}
int main()
{
	string s;
	cin>>s;
	
	cout<<longest_pallindromic_substr(s,0,s.size()-1)<<endl;
	
	cout<<lps_top(s,0,s.size()-1)<<endl;
}
