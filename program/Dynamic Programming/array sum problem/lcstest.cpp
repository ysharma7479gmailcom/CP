#include <bits/stdc++.h> 
using namespace std;

int LCS(char A[],char B[],int i,int j,int n1,int n2){
    if( i+1 > n1 || j+1 > n2)
        return 0;
    else if(A[i]==B[j]){
        return 1+LCS(A,B,i+1,j+1,n1,n2); 
    }
    else {
        return max(LCS(A,B,i+1,j,n1,n2),LCS(A,B,i,j+1,n1,n2));
    }
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
		int res=0;
	    int n1,n2;
	    cin>>n1>>n2;
	    char A[n1],B[n2];
	    for(int i=0;i<n1;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<n2;i++){
	        cin>>B[i];
	    }
	    res=LCS(A,B,0,0,n1,n2);
	    cout<<res<<endl;
	}
	return 0;
}
