

https://leetcode.com/problems/reducing-dishes/


class Solution {
public:
    int solve(vector<int>&satisfaction,int index,int time,vector<vector<int>>&dp){
        if(index==satisfaction.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];

        int include=satisfaction[index]*(time+1) +solve(satisfaction,index+1,time+1,dp);
        int exclude=0+solve(satisfaction,index+1,time,dp);

        dp[index][time]= max(include,exclude);
        return dp[index][time];
    }
    
    int solveTab(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //    No need of base case since we initialised dp with 0 that covers the base case;
       for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int include=satisfaction[index]*(time+1) +dp[index+1][time+1];
            int exclude=0+dp[index+1][time];

            dp[index][time]= max(include,exclude);

        }
       }
       return dp[0][0];
    }
    int solveTabOpt(vector<int>&satisfaction){
        int n=satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
    //    No need of base case since we initialised dp with 0 that covers the base case;
       for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int include=satisfaction[index]*(time+1) +next[time+1];
            int exclude=0+next[time];

            curr[time]= max(include,exclude);

        }
       next=curr;
       }
       return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // int n=satisfaction.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,0,dp);
        return solveTabOpt(satisfaction);
    }
};




class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int ans = 0, cur = 0, sum = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            sum += satisfaction[i];
            cur += sum;
            if (cur < ans) break;
            else ans = cur;
        }
        return ans;
    }
};