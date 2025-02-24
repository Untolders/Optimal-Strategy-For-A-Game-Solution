#################################################################################  Question  ################################################################################################################################################

You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
n = 4
arr[] = {5, 3, 7, 10}
Output: 
15
Explanation: The user collects maximum
value as 15(10 + 5). It is guarantee that we cannot get more than 15 by any possible moves.
Example 2:

Input:
n = 4
arr[] = {8, 15, 3, 7}
Output: 
22
Explanation: The user collects maximum
value as 22(7 + 15). It is guarantee that we cannot get more than 22 by any possible moves.
Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of n coins) and n as a number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(n*n)
Expected Auxiliary Space: O(n*n)

Constraints:
2 <= n <= 103
1 <= arr[i] <= 106









##################################################################################  Solution  ###############################################################################################################################################
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long dp[1001][1001];
    long long  solve(int i,int j,int arr[]){
        if(i==j)
        return arr[i];
        
        if(i>j)
        return 0;
        
        
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        long long l=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
        
        long long r=arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr));
        
        
        return dp[i][j]=max(l,r);
        
    }
    
    
    long long maximumAmount(int n, int arr[]){
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends

