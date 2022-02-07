#include<bits/stdc++.h>
using namespace std;

//using 2 array
int space_optimised_scs2(string s1,string s2,int m,int n)
{
	int curr[n+1],prev[n+1];
	for(int i=0;i<m+1;i++)
	{
			for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				curr[j]=i+j;
			else if(s1[i-1]==s2[j-1])
				curr[j]=prev[j-1]+1;
			else curr[j]=min(curr[j-1],prev[j])+1;
		}
		for(int k=0;k<n+1;k++)
			prev[k]=curr[k];
	}
	return curr[n];
}

//using 1 array

int space_optimised_scs1(string s1,string s2,int m,int n)
{
	int curr[n+1],prev;
	for(int i=0;i<m+1;i++)
	{
		prev=curr[0];
			for(int j=0;j<n+1;j++)
		{
			int back_up=curr[j];
			if(i==0 || j==0)
				curr[j]=i+j;
			else if(s1[i-1]==s2[j-1])
				curr[j]=prev+1;
			else curr[j]=min(curr[j],curr[j-1])+1;
			prev=back_up;
		}
		
	}
	return curr[n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int m=s1.size(),n=s2.size();
	
	cout<<space_optimised_scs2(s1,s2,m,n)<<endl;
		cout<<space_optimised_scs1(s1,s2,m,n)<<endl;
}
