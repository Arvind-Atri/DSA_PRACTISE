class Solution {
public:
    int solveSO(vector<int>& prices,int k) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;

                    if (buy) {
                        int Buy = -prices[index] + next[0][limit];
                        int skip = 0 + next[1][limit];
                        profit = max(Buy, skip);
                    } else {
                        int sell = prices[index] + next[1][limit - 1];
                        int skip = 0 + next[0][limit];
                        profit = max(sell, skip);
                    }

                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }

        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSO(prices, k);
    }
};






class Solution {
private: 
    int solveMem(int index,int opnum,int k, vector<int>& prices,vector<vector<int>> &dp)    
    {
        if(index==prices.size()) return 0;
        if(opnum==2*k) return 0;

        if(dp[index][opnum]!=-1) return dp[index][opnum];

        int profit=0;

        if(opnum%2==0)
        {
            //buy allowed
                int buykaro=-prices[index]+solveMem(index+1,opnum+1,k,prices,dp);
                int skipkaro=0+solveMem(index+1,opnum,k,prices,dp);
                 profit=max(buykaro,skipkaro);            
        }else
        {
            //sell allowed
                int sellkaro=+prices[index]+solveMem(index+1,opnum+1,k,prices,dp);
                int ignorekaro=0+solveMem(index+1,opnum,k,prices,dp);
                profit=max(sellkaro,ignorekaro);            
        }
        return dp[index][opnum]=profit;
    }    

public:
    int maxProfit(int k, vector<int>& prices) {

         int n=prices.size();
         vector<vector<int>> dp(n,vector<int> (2*k,-1));
         return solveMem(0,0,k,prices,dp);

    }
};