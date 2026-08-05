
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1432257042/


class Solution {
public:
    int solve(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;

        if(buy){
            int buyStock=-prices[index]+solve(index+1,0,prices,dp);
            int skipStock=0 + solve(index+1,1,prices,dp);
            profit=max(buyStock,skipStock);
        }
        else{
            int sellStock=prices[index]+solve(index+1,1,prices,dp);
            int skipStock=0 + solve(index+1,0,prices,dp);
            profit=max(sellStock,skipStock);
        }
        return dp[index][buy]= profit;
    }
    int solveTab(vector<int>&prices){
        int n=prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    int buyStock=-prices[index]+dp[index+1][0];
                    int skipStock=0 + dp[index+1][1];
                    profit=max(buyStock,skipStock);
                }
                else{
                    int sellStock=prices[index]+dp[index+1][1];
                    int skipStock=0 + dp[index+1][0];
                    profit=max(sellStock,skipStock);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
       
    }

     int solveTabOpt(vector<int>&prices){
        int n=prices.size();
    //    vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2,0);
        vector<int>next(2,0);
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    int buyStock=-prices[index]+next[0];
                    int skipStock=0 + next[1];
                    profit=max(buyStock,skipStock);
                }
                else{
                    int sellStock=prices[index]+next[1];
                    int skipStock=0 + next[0];
                    profit=max(sellStock,skipStock);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
       
    }


    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solveTab(prices);
    }
};