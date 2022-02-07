#include<bits/stdc++.h>
using namespace std;

int main()
{
	int *p = new int;
	cin>>*p;
	cout<<*p<<endl;
	
	*p.add(7);
	cout<<p[0]<<" "<<p[1]<<endl;
}
