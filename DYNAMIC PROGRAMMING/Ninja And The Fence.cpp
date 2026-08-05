#include <bits/stdc++.h> 
const int mod = 1e9 + 7;

https://www.youtube.com/watch?v=O3Rn-Kjr0p0

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

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<long long> dp(n + 1, -1);
    return fun(n, k, dp);
}





// Tabulation

#include <bits/stdc++.h> 
int numberOfWays(int n, int k) {
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
