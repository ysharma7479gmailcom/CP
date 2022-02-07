#include<bits/stdc++.h>
using namespace std;
int dp1[100][100];
int dp2[100][100];

int recur_LRS(string s1,string s2,int m, int n)
{
	if(m==0 || n==0)
			return 0;
	if(s1[m-1]==s2[n-1] && m!=n)
			return recur_LRS(s1,s2,m-1,n-1) + 1;
	else return max(recur_LRS(s1,s2,m,n-1),recur_LRS(s1,s2,m-1,n));
}

	//1--> top to bottom
		
int top_to_bottom_lrs(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)
		return 0;
	if(dp1[m][n]==0)
	{
	if(s1[m-1]==s2[n-1] && m!=n)
		dp1[m][n]=top_to_bottom_lrs(s1,s2,m-1,n-1)+1;
	else 
		dp1[m][n]=max(top_to_bottom_lrs(s1,s2,m-1,n),top_to_bottom_lrs(s1,s2,m,n-1));
	}
	return dp1[m][n];
}

//2--> bottom to top

int bottom_to_top_lrs(string s1,string s2,int m,int n)
{
	for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<n+1;j++)
				{
					if(i==0 || j==0)
						dp2[i][j]=0;
					else if(s1[i-1]==s2[j-1] && i!=j)
						dp2[i][j]=dp2[i-1][j-1]+1;
					else dp2[i][j]=max(dp2[i][j-1],dp2[i-1][j]);
				}
		}
	return dp2[m][n];
}
int main()
{
	string s;
	cin>>s;
	
	//recursive solution
	cout<<recur_LRS(s,s,s.size(),s.size())<<endl;
	
	//dynamic solution
	
		//1--> top to bottom
		
		cout<<top_to_bottom_lrs(s,s,s.size(),s.size())<<endl;
		
		//2--> bottom to top

		cout<<bottom_to_top_lrs(s,s,s.size(),s.size())<<endl;	
}
