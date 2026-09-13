

https://www.youtube.com/watch?v=O3Rn-Kjr0p0

#include <bits/stdc++.h> 
#define mod 1000000007
int solve(int n ,int k){
    if(n==1) return k;
    if(n==2) return (k*k);

    return (k-1)*(solve(n-1,k)%mod+solve(n-2,k)%mod);
}
long long fun(int n, int k, vector<long long>& dp) {
        if (n == 1) return k % mod;
        if (n == 2) return (k * k) % mod;
        
        if (dp[n] != -1) return dp[n];
        
        long long same = (fun(n - 1, k, dp) * (k - 1)) % mod;
        long long diff = (fun(n - 2, k, dp) * (k - 1)) % mod;
        
        long long result = (same + diff) % mod;
        
        dp[n] = result;
        return result;
}
int solveTab(int n ,int k){
    vector< long long int>dp(n+1);

    long long int mod=1e9 + 7;

    dp[0]=0;
    dp[1]=k%mod;
    dp[2]=(k*k)%mod;

    for(int i=3;i<=n;i++){
        dp[i]=(k-1)*(dp[i-1]+dp[i-2])%mod;
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<long long int>dp(n+1,-1);
    // return solve(n,k);
    return fun(n,k,dp);
}
