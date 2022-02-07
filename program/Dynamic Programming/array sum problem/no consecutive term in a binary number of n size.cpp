#include<bits/stdc++.h>
using namespace std;

int dp[100][2];
recur_sequence(int n,int l)
{
	if(n==0)return 0;
	
	if(n==1)
	{
		if(l==1)
			return 1;
		else return 2;
	}
	
	if(l==0) return recur_sequence(n-1,0)+recur_sequence(n-1,1);
	else return recur_sequence(n-1,0);
}

int dynamic(int n,int l)
{
	if(n==0)return 0;
	
	if(dp[n][l]==0)
	{
			if(n==1)
			{
				if(l==1)
				dp[n][l] = 1;
				else dp[n][l] = 2;
			}
		else
		{
			if(l==0) dp[n][l]=dynamic(n-1,0) + dynamic(n-1,1);
			else dp[n][l]=dynamic(n-1,0);
		}
	}
	return dp[n][l];
}

void dyna(int n,int l,string out)
{
	if(n==0)
	{
		cout<<out<<endl;
		return ;
	}
	
	dyna(n-1,0,out+"0");
	if(l==0)
		dyna(n-1,1,out + "1");
}
int main()
{
	int n;
	cin>>n;
	
	cout<<recur_sequence(n,0)<<endl;
	
	cout<<dynamic(n,0)<<endl;
	string s="";
	dyna(n,0,s);
}
