#include<bits/stdc++.h>
using namespace std;

int maxsize=0,m,n;
//int largest_square(int **mat)
//{
//	
//	if(m==0 || n==0)
//	{
//		maxsize=max(maxsize,mat[m][n]);
//		return mat[m][n];
//	}
//	
//	int top=largest_square(mat,m-1,n);
//	
//	int left=largest_square(mat,m,n-1);
//	int top_left=largest_square(mat,m-1,n-1);
//	int size=0;
//	if(mat[m][n] != 0)
//	{
//		size=1+min(top,min(left,top_left));
//	}
//	maxsize=max(maxsize,size);
//	return maxsize;
//}

int dynamic_largest_square(int **mat)
{
		int dp[m][n],r=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=mat[i][j];
			
			if(i && j && mat[i][j])
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			
			r=max(r,dp[i][j]);
		}
	}
	return r;
}
int main()
{

	cin>>m>>n;
	int **mat=new int*[m];
	
	for(int i=0;i<m;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>mat[i][j];
	}
	
	//recursive
//	cout<<largest_square(mat,m-1,n-1)<<endl;

//dynamic
cout<<dynamic_largest_square(mat);
}
