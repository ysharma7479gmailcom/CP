#include<bits/stdc++.h>
using namespace std;
map<string,int> m;

//int dynamic(string s[],int n)
//{
//string key="";
//	for(int i=0;i<n;i++)
//	{
//			if(s[i].size()==0)
//			return 0;
//		key=key+(char(s[i].size()));
//	}
//	
//	if(m[key]==0)
//	{
//		int r=0;
//		for(int i=0;i<n;i++)
//	{
//		if(s[0][s[0].size()-1]!=s[i][s[i].size()-1])
//			{
//			r=1;
//			break;
//			}
//	}
//	
//	if(r==0)
//	{
//		for(int i=0;i<n;i++)
//			s[i]=s[i].substr(0,s[i].size()-1);
//		m[key]=dynamic(s,n) + 1;
//	}
//	else
//	{
//		int k=INT_MIN;
//		for(int i=0;i<n;i++)
//		{
//			string t=s[i];
//			s[i]=s[i].substr(0,s[i].size()-1);
//			k=max( k , dynamic(s,n));
//			s[i]=t;
//		}
//		m[key]=k;
//	}
//	
//	}
//	return m[key];
//	
//}
int dp[100];
int recur(int s[],int n)
{
	if(n<=0)return 0;

	return max( (recur(s,n-2) + s[n-1]) , (recur(s,n-1)));

}

int dynamic(int s[],int n)
{
		if(n<=0)return 0;
		
		if(dp[n]==0)
		{
			dp[n]=max( (dynamic(s,n-2) + s[n-1]) , (dynamic(s,n-1)));
		}
		return dp[n];
}
int main()
{
	int n;
	cin>>n;
	int s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	
	cout<<recur(s,n)<<endl<<dynamic(s,n);
	
}
