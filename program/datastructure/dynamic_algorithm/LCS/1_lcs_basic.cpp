#include<bits/stdc++.h>
using namespace std;

int dp1[10][10],dp2[10][10];

//recursive
int recurlcs(string s1,string s2,int m,int n)
{
			
			if(m==0 || n==0)
				return 0;
				
			if(s1[m-1]==s2[n-1])
				return recurlcs(s1,s2,m-1,n-1)+1;
			
			else
				return max( recurlcs(s1,s2,m-1,n) , recurlcs(s1,s2,m,n-1) );
}


//top to bottom
	int top_to_bottom_lcs(string s1,string s2,int m,int n)
	{
		if(m==0 || n==0)return 0;
		
		if(dp1[m][n]==0)
			{
				if(s1[m-1]==s2[n-1])
					dp1[m][n]=top_to_bottom_lcs(s1,s2,m-1,n-1)+1;
				else
					dp1[m][n]=max( top_to_bottom_lcs(s1,s2,m-1,n) , top_to_bottom_lcs(s1,s2,m,n-1) );
			}
			return dp1[m][n];
	}
	
//bottom to top
	
	int bottom_to_top_lcs(string s1,string s2,int m,int n)
	{
		for(int i=0;i<m+1;i++)
		{
			for(int j=0;j<n+1;j++)
				
				if(i==0 || j==0)
					dp2[i][j]=0;
				
				else if(s1[i-1]==s2[j-1])
						dp2[i][j]=dp2[i-1][j-1]+1;
				else dp2[i][j]=max( dp2[i-1][j] , dp2[i][j-1]);
		}
		return dp2[m][n];
	}
int main()
{
	string s1,s2; //aacd // bfec
	
	cout<<"please enter the two string to find their longest common subsequence"<<endl;
	cin>>s1>>s2;
	
	int m=s1.size();
	int n=s2.size();
	
	//recursive
		cout<<recurlcs(s1,s2,m,n)<<endl;
		
	//top to bottom
		cout<<top_to_bottom_lcs(s1,s2,m,n)<<endl;
		
	//bottom to top
	
		cout<<bottom_to_top_lcs(s1,s2,m,n)<<endl;
		
		
}
