#include<bits/stdc++.h>
using namespace std;


int sequence(int *a,int n)
{
	vector<int> v1(n+1,INT_MIN),v2(n,INT_MIN),v3(n-1,INT_MIN),v4(n-2,INT_MIN);
	
	for(int i=n-1;i>=0;i--)
		v1[i]=max(v1[i+1],a[i]);
		
	for(int i=n-2;i>=0;i--)
		v2[i]=max(v2[i+1],v1[i+1]-a[i]);
		
	for(int i=n-3;i>=0;i--)
		v3[i]=max(v3[i+1],v2[i+1]+a[i]);
		
	for(int i=n-4;i>=0;i--)
	v4[i]=max(v4[i+1],v3[i+1]-a[i]);
		
		return v4[0];
		
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	// max value of a[s]-a[r] +a[p] -a[q] where s>r>p>q;
	cout<<sequence(a,n)<<endl;
	
	
	
}
