#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int find(int arr[],int sum,int n){
    bool dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    int ans=INT_MAX;
    for(int i=0;i<=sum/2;i++)
        {
        if(dp[n][i]){ans=min(ans,abs(sum-(2*i))); // given difference x then return abs(sum-(2*i))=x 
        }
        }
    
    return ans;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int sum=0;
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	   
	  
	        int value=find(arr,sum,n);
	       cout<<value<<endl;
	    }
	
}

