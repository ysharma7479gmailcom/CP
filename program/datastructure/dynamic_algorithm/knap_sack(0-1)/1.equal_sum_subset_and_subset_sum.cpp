#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//1.equal sum partition and 2.subset sum partiton
bool find(int arr[],int sum,int n){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
        {
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
            else
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];  // 3.count subset sum change dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    return dp[n][sum];
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
	   
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }
	    else{
	        
	        int value=find(arr,sum/2,n);
	        if(value==0)
	            cout<<"NO"<<endl;
	        else
	            cout<<"YES"<<endl;
	    }
	}
}

