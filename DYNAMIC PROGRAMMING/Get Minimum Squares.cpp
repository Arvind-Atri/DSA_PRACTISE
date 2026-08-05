//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int solveTab(int n){
      vector<int>dp(n+1,INT_MAX);
      
      dp[0]=0;
      
      for(int i=1;i<=n;i++){
          for(int j=1;j*j<=n;j++){
              int temp=j*j;
              if(i-temp>=0)
              dp[i]=min(dp[i],1+dp[i-temp]);
          }
      }
      return dp[n];
  }
  
  
  int solve(int n,vector<int>&dp){
      if(n==0) return 0;
      int ans=n;
      if(dp[n]!=-1) return dp[n];
      for(int i=1;i*i<=n;i++){
         ans=min(ans,solve(n-i*i,dp)+1); 
      }
      dp[n]=ans;
      return dp[n];
  }
  
  
  
    int MinSquares(int n) {
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        return solveTab(n);
    }
};


int solveTab(int n){
    vector<int>dp(n+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            int temp=j*j;
            if(i-temp>=0)
            dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
    return dp[n];
}