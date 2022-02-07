#include<bits/stdc++.h>
using namespace std;
int ans=0;
int recur_min_coin(int *p,int n,int s)
{
	if(s==0) return 0;
	if(s<0) return INT_MIN;
	if(n==0)return INT_MIN;
	cout<<n<<" "<<s<<endl;
	
	int incl=recur_min_coin(p,n,s-p[n-1])+1;
	int excl=recur_min_coin(p,n-1,s);
	return max(incl,excl);
	
}
int main()
{
	int n;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++)cin>>p[i];
	int s;
	cin>>s;
	
	cout<<recur_min_coin(p,n,s)<<endl;
}
