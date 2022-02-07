#include<bits/stdc++.h>
using namespace std;

int ans=0,r=0;
map<string,int> dp;
void recur_min_cost(int **mat,int i,int j,int c)
{
	c=c-mat[i][j];
	if(i==0 && j==0)
	{
	if(c==0)
		{
			
		ans++;
		return;
		}
	else return;
	}
	if(c<0)
	return;
	if(i==0 && j>0)
	{
		recur_min_cost(mat,i,j-1,c);
		return ;	
	}
	if(j==0 && i>0)
	{
		recur_min_cost(mat,i-1,j,c);
		return;
	}
	else 
	{
		recur_min_cost(mat,i-1,j,c);
		recur_min_cost(mat,i,j-1,c);
		return;
	}
}

int dynamic_min_cost(int **mat,int m,int n,int c)
{
	if(c<0 || m<0 || n<0)return 0;
	if(m==0 && n==0)
	{
	if(c==mat[m][n])
	{
	return 1;
	}
	 return 0;
	}
	
	string key=char(m+48) + "|" + char(n+48) + "|" + char(c+48); // only problem

	if(dp.find(key)==dp.end())
	{
	    
		if(m==0)
			dp[key]=dynamic_min_cost(mat,m,n-1,c-mat[m][n]);
	else if(n==0)
			dp[key]=dynamic_min_cost(mat,m-1,n,c-mat[m][n]);
		else 
		{
		    
		    int t1=dynamic_min_cost(mat,m,n-1,c-mat[m][n]);
		    int t2=dynamic_min_cost(mat,m-1,n,c-mat[m][n]);
			dp[key]=t1+t2;
		}
	}
	
	return dp[key];
}
int main()
{
	int m,n,cost;
	cin>>m>>n>>cost;
	int **mat=new int*[m];
	
	for(int i=0;i<m;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
		cin>>mat[i][j];
	}
	
int t=dynamic_min_cost(mat,m-1,n-1,cost);
cout<<t<<endl;
recur_min_cost(mat,m-1,n-1,cost);
cout<<ans<<endl;

}
