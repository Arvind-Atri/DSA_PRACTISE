class Solution {
public:
    int mod = 1e9 + 7;
    // int solveMem(int dice, int faces, int target,vector<vector<long long>>& dp) {
    //     if (target < 0)
    //         return 0;

    //     if (target == 0 && dice != 0)
    //         return 0;

    //     if (dice == 0 && target != 0)
    //         return 0;

    //     if (dice == 0 && target == 0)
    //         return 1;

    //     if (dp[dice][target] != -1)
    //         return dp[dice][target];
    //     long long ans = 0;
    //     for (int i = 1; i <= faces; i++) {
    //         if (i <= target)
    //             ans += solveMem(dice - 1, faces, target - i, dp) % mod;
    //     }
        
        
        
        
        
        
        
        
        int solveTab(int dice, int faces, int target) {
            vector<vector<long long>> dp(dice + 1,vector<long long>(target + 1, 0));
            dp[0][0] = 1;

            for (int d = 1; d <= dice; d++) {
                for (int t = 1; t <= target; t++) {
                    long long ans = 0;

                    for (int i = 1; i <= faces; i++) {
                        if (t-i>=0)
                            ans=ans+ dp[d - 1][t - i] % mod;
                    }
                    dp[d][t] = ans % mod;
                }
            }
            return dp[dice][target];
        }
        int numRollsToTarget(int n, int k, int target) {
            // vector<vector<long long>> dp(n + 1,vector<long long>(target + 1, -1));
            return solveTab(n, k, target);
        }
    };