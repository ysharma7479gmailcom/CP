#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

//1. code for single lcs
string print_lcs(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)
		return "";
	if(s1[m-1]==s2[n-1])
		return print_lcs(s1,s2,m-1,n-1)+s1[m-1];
	if(dp[m-1][n]>dp[m][n-1])
		return print_lcs(s1,s2,m-1,n);
	else return print_lcs(s1,s2,m,n-1);
}

// 2.code for all lcs

vector<string> vector_all_lcs(string s1,string s2,int m, int n)
{
	if(n==0 || m==0)
	{
		vector<string> v(1);
		return v;
	}
	
	if(s1[m-1]==s2[n-1])
	{
		vector<string> templ=vector_all_lcs(s1,s2,m-1,n-1);
		
		for(int i=0;i<templ.size();i++)
			templ[i].push_back(s1[m-1]);
			
		return templ;
	}
	
	if(dp[m-1][n] > dp[m][n-1])
		return vector_all_lcs(s1,s2,m-1,n);
	else if(dp[m][n-1] > dp[m-1][n])
		return vector_all_lcs(s1,s2,m,n-1);
	
	if(dp[m-1][n]==dp[m][n-1])
		{
			vector<string> top=vector_all_lcs(s1,s2,m-1,n);
			vector<string> left=vector_all_lcs(s1,s2,m,n-1);
			
			top.insert(top.end(), left.begin(), left.end());
			return top;
		}
		
}

int bottom_to_top_lcs(string s1,string s2,int m,int n)
{
		for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<n+1;j++)
				
				if(i==0 || j==0)
					dp[i][j]=0;
				
				else if(s1[i-1]==s2[j-1])
						dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max( dp[i-1][j] , dp[i][j-1]);
		}
		return dp[m][n];
}
int main()
{
	string s1,s2;
	
	cout<<"please enter the two string to find their longest common subsequence"<<endl;
	cin>>s1>>s2;
	
	int m=s1.size();
	int n=s2.size();

		cout<<bottom_to_top_lcs(s1,s2,m,n)<<endl;
		cout<<print_lcs(s1,s2,m,n)<<endl;
		
}
