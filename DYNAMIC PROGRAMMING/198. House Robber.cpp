class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];        
    }
};






// Memoisation

class Solution {
public:
    int solve(vector<int>&dp,vector<int>&nums,int n){
        

        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int incl=solve(dp,nums,n-2)+nums[n];
        int excl=solve(dp,nums,n-1)+0;

        dp[n]= max(incl,excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return nums[0];
        vector<int>dp(n,-1);
        return solve(dp,nums,n-1);
    }
};