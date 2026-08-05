class Solution {
public:
    bool solve(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
            if(index>=nums.size()) return 0;

            if(target<0) return 0;
            if(target==0) return 1;

            if(dp[index][target]!=-1) return dp[index][target];

            bool incl=solve(index+1,nums,target-nums[index],dp);
            bool excl=solve(index+1,nums,target,dp);

            return dp[index][target]= incl or excl;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total&1) return 0;

        int target=total/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};