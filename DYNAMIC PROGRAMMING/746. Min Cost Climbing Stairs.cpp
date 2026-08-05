class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];
        if (dp[n] != -1)
            return dp[n];

        dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};






// Tabulatin

int minCostClimbingStairs(vector<int> &cost)
       	{
       	    int n = cost.size();
       	    vector<int> dp(n, -1);
       	    dp[0] = cost[0];
       	    dp[1] = cost[1];
       	    for (int i = 2; i < n; i++)
       	        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
       	    return min(dp[n - 1], dp[n - 2]);
       	}


// Space Optimised

 int solve2(vector<int>&cost,int n){
        

        int prev2=cost[0];
        int prev1=cost[1];

        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
       
    }