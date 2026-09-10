class Solution {
public:
    // int solve(vector<int>&dp,vector<int>&cost,int n){
    //     if(n==0 || n==1){
    //         return cost[n];
    //     }
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=min(solve(dp,cost,n-1),solve(dp,cost,n-2))+cost[n];
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     // vector<int>dp(n+1,-1);
    //     // return min(solve(dp,cost,n-1),solve(dp,cost,n-2));
    //     if(n==0||n==1) return cost[n];
    //     vector<int>dp(n+1);
    //     dp[0]=cost[0];
    //     dp[1]=cost[1];
    //     for(int i=2;i<n;i++){
    //         dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    //     }
    //     return min(dp[n-1],dp[n-2]);

    // }
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int>dp(n+1,-1);
        // return min(solve(dp,cost,n-1),solve(dp,cost,n-2));
        if(n==0||n==1) return cost[n];
        // vector<int>dp(n+1);
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++){
            int curr=min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);

    }
};
