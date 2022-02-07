#include<bits/stdc++.h>
using namespace std;

int recurlcs(string s1,string s2,string s3,int m,int n,int o)
{
	if(m==0 || n==0 || o==0)return 0;
	else if(s1[m-1]==s2[n-1] && s1[m-1]==s3[o-1])
			return recurlcs(s1,s2,s3,m-1,n-1,o-1)+1;
	else return max( recurlcs(s1,s2,s3,m-1,n,o) , max( recurlcs(s1,s2,s3,m,n-1,o) , recurlcs(s1,s2,s3,m,n,o-1) ));
}

//bottom to top
	
 int bottom_to_top_lcs(string s1,string s2,string s3,int m,int n,int o)
 	{
 		int dp[m+1][n+1][o+1];
 		
 		memset(dp,0,sizeof(dp));
 		for(int i=1;i<m+1;i++)
 		{
			 	for(int j=1;j<n+1;j++)
			 	{
				 	for(int k=1;k<o+1;k++)
 				
				 	{
						if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1])
 						dp[i][j][k]=dp[i-1][j-1][k-1]+1;
 					else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				 	}
				}
		}
 		return dp[m][n][o];
	 }
	
int main()
{
	string s1,s2,s3;
	
	cout<<"please enter the three string to find their longest common subsequence"<<endl;
	cin>>s1>>s2>>s3;
	
	int m=s1.size();
	int n=s2.size();
	int o=s3.size();
	//recursive
		cout<<recurlcs(s1,s2,s3,m,n,o)<<endl;
		
		
	//bottom to top
	
	cout<<bottom_to_top_lcs(s1,s2,s3,m,n,o)<<endl;
		
		
}
