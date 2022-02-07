#include<bits/stdc++.h>
using namespace std;
 int dp[10][100];
 long long int r=0,p=0;
int count_keypad(int i,int n)
{
	r++;
	if(n==1)return 1;
	if(i==0)
	{
		return count_keypad(i,n-1) + count_keypad(i+8,n-1);
	}
	else if(i==1)
	{
	return	count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i+3,n-1);
	}
	
	else if(i==2)
	{
		return count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i+3,n-1) + count_keypad(i-1,n-1);
	}
	
	else if(i==3)
	{
		return count_keypad(i,n-1) + count_keypad(i-1,n-1) + count_keypad(i+3,n-1);
	}
	
	else if(i==4)
	{
		return count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i+3,n-1) + count_keypad(i-3,n-1) ;
	}
	
	else if(i==5)
	{
	return	count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i-1,n-1) + count_keypad(i+3,n-1) + count_keypad(i-3,n-1) ;
	}
	
	else if(i==6)
	{
	return	count_keypad(i,n-1) + count_keypad(i-1,n-1) + count_keypad(i+3,n-1) + count_keypad(i-3,n-1);
	}
	
	else if(i==7)
	{
	return	count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i-3,n-1);
	}
	
	else if(i==8)
	{
	return	count_keypad(i,n-1) + count_keypad(i+1,n-1) + count_keypad(i-3,n-1) + count_keypad(i-1,n-1) + count_keypad(0,n-1);
	}
	
	else if(i==9)
	{
	return	count_keypad(i,n-1) + count_keypad(i-1,n-1) + count_keypad(i-3,n-1);
	}
	
}

int dynamic(int i,int n)
{
	p++;
	if(n==1)return 1;
	
	if(dp[i][n]==0)
	{
	if(i==0)
		dp[i][n]= dynamic(i,n-1) + dynamic(i+8,n-1);
	else if(i==1)
	   dp[i][n]=dynamic(i,n-1) + dynamic(i+1,n-1) +dynamic(i+3,n-1);
	
	else if(i==2)
		dp[i][n]= dynamic(i,n-1) + dynamic(i+1,n-1) + dynamic(i+3,n-1) + dynamic(i-1,n-1);
	else if(i==3)
		dp[i][n]= dynamic(i,n-1) + dynamic(i-1,n-1) + dynamic(i+3,n-1);
	else if(i==4)
		dp[i][n]= dynamic(i,n-1) + dynamic(i+1,n-1) + dynamic(i+3,n-1) + dynamic(i-3,n-1) ;
	else if(i==5)
	dp[i][n]=	dynamic(i,n-1) + dynamic(i+1,n-1) + dynamic(i-1,n-1) + dynamic(i+3,n-1) + dynamic(i-3,n-1) ;
	else if(i==6)
	dp[i][n]=	dynamic(i,n-1) + dynamic(i-1,n-1) + dynamic(i+3,n-1) + dynamic(i-3,n-1);
	else if(i==7)
	{
	dp[i][n]=dynamic(i,n-1) + dynamic(i+1,n-1) + dynamic(i-3,n-1);
	}
	else if(i==8)
	{
	dp[i][n]=	dynamic(i,n-1) + dynamic(i+1,n-1) + dynamic(i-3,n-1) + dynamic(i-1,n-1) + dynamic(0,n-1);
	}
	
	else if(i==9)
	{
	dp[i][n]=	dynamic(i,n-1) + dynamic(i-1,n-1) + dynamic(i-3,n-1);
	}
	
	}
	return dp[i][n];
}
int main()
{
	int n;
	cin>>n;
	
	int s=0;
	
	for(int i=0;i<10;i++)
	{
	int t=count_keypad(i,n);
		cout<<i<<"  -> "<<t<<endl;
	s=s+t;
	}
	
	cout<<s<<endl;
	s=0;
	for(int i=0;i<10;i++)
	{
	int t=dynamic(i,n);
		cout<<i<<"  -> "<<t<<endl;
	s=s+t;
	}
	cout<<s<<endl;
	cout<<"r -> "<<r<<endl;
	cout<<"p -> "<<p<<endl;
}
