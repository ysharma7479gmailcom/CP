#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool pal[100][100];
void find_pall(string s)
{
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=i;j<s.size();j++)
		{
			if(i==j)
				pal[i][j]=true;
			else if(s[i]==s[j])
			{
				if(i+1==j)
					pal[i][j]=true;
				else pal[i][j]=pal[i+1][j-1];
			}
		}
	}
}
//bool ispall(string s,int i,int j)
//{
//	while(i<=j)
//	{
//		if(s[i]!=s[j])
//			return false;
//		i++;
//		j--;
//	}
//	return true;
//}
int recur_min_cut(string s,int i,int j)
{
	if(i==j || pal[i][j])
		return 0;
	
	int m=INT_MAX;
	
	for(int k=i;k<j;k++)
	{
		int c=1+recur_min_cut(s,i,k)+recur_min_cut(s,k+1,j);
		m=min(m,c);
	}
	return m;
}

int dynamic(string s,int i,int j)
{
	if(i==j || pal[i][j])
			return 0;
	
	if(dp[i][j]==0)
	{
		dp[i][j]=INT_MAX;
		for(int k=i;k<j;k++)
		{
		int c=1+dynamic(s,i,k)+dynamic(s,k+1,j);
		dp[i][j]=min(dp[i][j],c);	
		}
	}
	
	return dp[i][j];
}

int bottom_dynamic(string s)
{
	int n=s.size();
	int d[n];
	
	for(int i=n-1;i>=0;i--)
	{
		d[i]=INT_MAX;
		if(pal[i][n-1])
			d[i]=0;
		
		for(int j=n-2;j>=i;j--)
		{
			if(pal[i][j])
				d[i]=min(d[i],1+d[j+1]);
		}
	}
	return d[0];
}
int main()
{
	string s;
	cin>>s;
	find_pall(s);
	cout<<recur_min_cut(s,0,s.size()-1)<<endl;  // exponential

	cout<<dynamic(s,0,s.size()-1)<<endl;  // n  cube
	cout<<bottom_dynamic(s);			// n squre
	
}
