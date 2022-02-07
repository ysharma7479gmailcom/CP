 #include<bits/stdc++.h>
using namespace std;

int space_optimised_lcs(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)return 0;
	
	int curr[n+1],prev[n+1];
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)curr[j]=0;
			else if(s1[i-1]==s2[j-1])
				curr[j]=prev[j-1]+1;
			else curr[j]=max(curr[j-1],prev[j]);
		}
		
		for(int k=0;k<n+1;k++)prev[k]=curr[k];
	}
	return curr[n];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	cout<<space_optimised_lcs(s1,s2,s1.size(),s2.size());
}
