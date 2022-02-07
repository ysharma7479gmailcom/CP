#include<bits/stdc++.h>
using namespace std;

void build_segment_tree(int *tree,int *a,int index,int s,int e)
{

	if(s>e)return;
	
	if(s==e)
		{
		tree[index]=a[s];
		return ;
		}
	
	int mid=(s+e)/2;
	
	build_segment_tree(tree,a,2*index,s,mid);
	build_segment_tree(tree,a,2*index+1,mid+1,e);
	
	int left=tree[2*index];
	int right=tree[(2*index)+1];
	
	
	tree[index]=min(left,right) ;// for minimum range query; 
}



int query_min(int *tree,int index,int s,int e,int l,int r)
{
	cout<<s<<"  "<<e<<" "<<endl;
	if(s>=l && r>=e)
		return tree[index];

	if( r<s || l>e)
	{
		return INT_MAX;
	}
	
	
	int mid=(s+e)/2;
	
	int left=query_min(tree,2*index,s,mid,l,r);
	int right=query_min(tree,2*index+1,mid+1,e,l,r);
	return min(left,right);
	
}



void updatenode(int *tree,int index,int s,int e,int i,int val)
{
	if(i<s || i>e)return ;
	if(s==e)
	{
		tree[index]=val;
		return;
	}
	
	int mid=(s+e)/2;
	
	updatenode(tree,2*index,s,mid,i,val);
	updatenode(tree,2*index+1,mid+1,e,i,val);
	
	tree[index]=min(tree[2*index],tree[2*index+1]);
	
}


int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int *tree = new int[(4*n)+1];

	int index=1,start=0,end=n-1;//[0,n-1] carry ans by node 1 of tree;
	 
	build_segment_tree(tree,a,index,start,end);

    cout<<query_min(tree,1,start,end,0,3)<<endl;
	
	
	for(int i=0;i<(4*n+2);i++)
		cout<<tree[i]<<" ";
		cout<<endl;
   
   updatenode(tree,1,start,end,1,4);

	for(int i=0;i<(4*n+2);i++)
			cout<<tree[i]<<" ";
			cout<<endl;


}
