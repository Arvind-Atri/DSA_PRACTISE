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