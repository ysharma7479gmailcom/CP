#include<bits/stdc++.h>
using namespace std;


int linear_space_optimised_lcs(string s1,string s2)
{
	int m=s1.size(),n=s2.size();
	
	int curr[n+1],prev;
	memset(curr,0,sizeof(curr));
	for(int i=0;i<m+1;i++)
	{
		prev=curr[0];
		for(int j=0;j<n+1;j++)
		{
			int backup=curr[j];
			if(i==0 || j==0)
				curr[j]=0;
			else if(s1[i-1]==s2[j-1])
					curr[j]=prev+1;
			else curr[j]=max(curr[j],curr[j-1]);
			
			prev=backup;
		}
	}
	
	return curr[n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()>s2.size())
		cout<<linear_space_optimised_lcs(s1,s2);
	else cout<<linear_space_optimised_lcs(s2,s1);
}
