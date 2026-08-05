#include <vector>
#define mod 1000000007
long long int solveMem(int n , vector<long long int>&dp){
    if(n == 0){
        return 0;
    }
    if(n ==2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] =( ( (n-1)%mod) * ( (solveMem(n-1,dp) % mod) + (solveMem(n-2,dp) % mod) ) %mod);

    return dp[n];

}
long long int countDerangements(int n) {
    vector<long long int>dp(n+1, -1);
    return solveMem(n,dp);
}

int solveTab(int n)
{
    vector<int> dp(n + 1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;

        long long int sum = (first + second) % MOD;

        long long int ans = (i - 1) * sum % MOD;

        dp[i] = ans;
    }
    return dp[n];
}