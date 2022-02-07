#include<bits/stdc++.h>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int m,n;
bool isValid(int i,int j)
{
	return (i>=0 && i<m && j>=0 && j<n);
}
string recur_sequence(int **mat,int i,int j)
{
	if(!(isValid(i,j) ))
		return "0";
	
	cout<<i<<"-"<<j<<endl;
		
		string path;
	if( (i > 0)&& mat[i-1][j]-mat[i][j]==1)
		path=recur_sequence(mat,i-1,j);
	if( j+1 < n && mat[i][j+1]-mat[i][j]==1)
		path=recur_sequence(mat,i,j+1);
		
	if( i+1 < m && mat[i+1][j]-mat[i][j]==1)
		path=recur_sequence(mat,i+1,j);
	if( j > 0 && mat[i][j-1]-mat[i][j]==1)
		path=recur_sequence(mat,i,j-1);
		
	
	
	cout<<path<<endl;	
	return char(mat[m][n])+" - "+path;	
}
int main()
{
	
	cin>>m>>n;
	
	int **mat=new int*[m];
	
	for(int i=0;i<m;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	string t=recur_sequence(mat,0,0);
	cout<<t<<endl;
//	string result;
//	int ma=0;
//	for(int i=0;i<m;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//		 t=recur_sequence(mat,i,j);
//			int size=count(t.begin(),t.end(),'-');
//			if(size > ma)
//			{
//				result=t;
//				ma=t.size();	
//			}	
//		}
//	}
//	cout<<result<<endl;
}
