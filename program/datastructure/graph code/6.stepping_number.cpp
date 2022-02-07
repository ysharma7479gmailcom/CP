// A C++ program to find all the Stepping Numbers 
// in range [n, m] using DFS Approach 
#include<bits/stdc++.h> 
using namespace std; 

// Prints all stepping numbers reachable from num 
// and in range [n, m] 
void dfs(int n, int m, int stepNum) 
{ 
	// If Stepping Number is in the 
	// range [n,m] then display 
	if (stepNum <= m && stepNum >= n) 
		cout << stepNum << " "; 

	// If Stepping Number is 0 or greater 
	// than m, then return 
	if (stepNum == 0 || stepNum > m) 
		return ; 

	// Get the last digit of the currently 
	// visited Stepping Number 
	int lastDigit = stepNum % 10; 

	// There can be 2 cases either digit 
	// to be appended is lastDigit + 1 or 
	// lastDigit - 1 
	int stepNumA = stepNum*10 + (lastDigit-1); 
	int stepNumB = stepNum*10 + (lastDigit+1); 

	// If lastDigit is 0 then only possible 
	// digit after 0 can be 1 for a Stepping 
	// Number 
	if (lastDigit == 0) 
		dfs(n, m, stepNumB); 

	// If lastDigit is 9 then only possible 
	// digit after 9 can be 8 for a Stepping 
	// Number 
	else if(lastDigit == 9) 
		dfs(n, m, stepNumA); 
	else
	{ 
		dfs(n, m, stepNumA); 
		dfs(n, m, stepNumB); 
	} 
} 

// Method displays all the stepping 
// numbers in range [n, m] 
void displaySteppingNumbers(int n, int m) 
{ 
	// For every single digit Number 'i' 
	// find all the Stepping Numbers 
	// starting with i 
	for (int i = 0 ; i <= 9 ; i++) 
		dfs(n, m, i); 
} 

//Driver program to test above function 
int main() 
{ 
	int n = 0, m = 21; 

	// Display Stepping Numbers in 
	// the range [n,m] 
	displaySteppingNumbers(n,m); 
	return 0; 
} 

