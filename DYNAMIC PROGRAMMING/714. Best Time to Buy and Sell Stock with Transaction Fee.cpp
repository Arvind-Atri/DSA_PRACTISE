class Solution {
public:
     int solveTabOpt(vector<int>&prices,int fee){
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
                    int sellStock=prices[index]+next[1]-fee;
                    int skipStock=0 + next[0];
                    profit=max(sellStock,skipStock);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
       
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveTabOpt(prices,fee);
    }
};