// link   -https://leetcode.com/problems/coin-change/description/


class Solution {
public:
    int solve(vector<int>&coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
            

        }
        return mini;
    }
    int solveMem(vector<int>&coins,int x,vector<int>&dp){
        if(x==0) return 0;
        if(x<0) return INT_MAX;
        if(dp[x]!=-1) return dp[x];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solveMem(coins,x-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
            

        }
        return dp[x]= mini;
    }
    int solveTab(vector<int>&nums,int x){
        // if(x==0) return 0;
        
        vector<int>dp(x+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=x;i++){
            // calculating for every amount->x
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0 and dp[i-nums[j]]!=INT_MAX )
                dp[i]=min(dp[i],1+dp[i-nums[j]]);
            }
        }
        int ans=dp[x];
        if(ans==INT_MAX) return -1;
        else return ans;

    }
    int coinChange(vector<int>& coins, int amount) {
    //  int ans=solve(coins,amount);
    // vector<int>dp(amount+1,-1);
    //  int ans=solveMem(coins,amount,dp);
    //  if(ans==INT_MAX) return -1;
    //  else return ans;
    return solveTab(coins,amount);
    }
};
