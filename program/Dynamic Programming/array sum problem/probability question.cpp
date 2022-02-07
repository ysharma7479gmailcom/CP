#include<bits/stdc++.h>
using namespace std;
int r=0,d=0;
float dp[100][100][100];
float recur_probability(int x,int y,int n,int N)
{
	r++;
	if(n==0)
		return 1.0;
	
	float p=0.0;
	if(x>0)
		p=p+(.25*recur_probability(x-1,y,n-1,N));
	if(x<N-1)
		p=p+(.25*recur_probability(x+1,y,n-1,N));
	if(y>0)
		p=p+(.25*recur_probability(x,y-1,n-1,N));
	if(y<N-1)
		p=p+(.25*recur_probability(x,y+1,n-1,N));
		
	return p;
		
}

float dyna(int x,int y,int n,int N)
{
	d++;
	if(n==0)
	return 1.0;
	
	if(dp[x][y][n]==0)
	{
	float p=0.0;
	if(x>0)
		p=p+(.25*dyna(x-1,y,n-1,N));
	if(x<N-1)
		p=p+(.25*dyna(x+1,y,n-1,N));
	if(y>0)
		p=p+(.25*dyna(x,y-1,n-1,N));
	if(y<N-1)
		p=p+(.25*dyna(x,y+1,n-1,N));
		dp[x][y][n]=p;
	}
	return dp[x][y][n];
}
int main()
{
	int n,x,y,N;
	cin>>n>>x>>y>>N;
	
	cout<<recur_probability(x,y,n,N)<<endl;
	cout<<dyna(x,y,n,N)<<endl;
	cout<<r<<endl<<d;
}
