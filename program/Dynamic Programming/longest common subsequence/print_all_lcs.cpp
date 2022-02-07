#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

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
void lcs_make_table(string s1,string s2)
{
	for(int i=0;i<s1.size()+1;i++)
	{
		for(int j=0;j<s2.size()+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	cout<<dp[s1.size()][s2.size()]<<endl;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	lcs_make_table(s1,s2);
	
	vector<string> v=vector_all_lcs(s1,s2,s1.size(),s2.size());
	map<string,int> m;
	for(int i=0;i<v.size();i++)
	{
		if(m[v[i]]==0)
			{
				m[v[i]]=1;
				cout<<v[i]<<endl;
			}
		}	
}
