/*

Those who forget the past,
are condemned to repeat it.

*/

//  ----- 2 Approaches------
// 1.Top Down Approach ->Recursion +Memoisation

// 2.Bottom-up Approach -> Tabulation
// --------
// then ->Space Optimisation


// Fibonacci Series 

// Memoisation


#include<bits/stdc++.h>
using namespace std;

// Tc=Sc=O(n)
int fib(int n,vector<int>&dp){
        if(n<=1){
                return n;

        }
        if(dp[n]!=-1){
                return dp[n];
        }
        dp[n] =fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}


int main()
{
       int n;
       cin>>n;

       vector<int>dp(n+1);
       for(int i=0;i<=n;i++){
               dp[i]=-1;
       }

       cout<<fib(n,dp);
       return 0;
}




// Tabulation
// Tc=Sc=O(n)
int fib(){
       

       vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
       for(int i=2;i<=n;i++){
               dp[i]=dp[i-1]+dp[i-2];
       }

       cout<<dp[n];
       return 0;
}




// Space Optimisation

// Tc=O(n)
// sc=O(1)

int main()
{
       int n;
       cin>>n;

       int prev1=1;
       int prev2=0;
       for(int i=2;i<=n;i++){
               int curr=prev1+prev2;
               prev2=prev1;
               prev1=curr;
       }

       cout<<prev1<<endl;
       return 0;
}