class Solution {
public:
    int solve(vector<int>& nums,int index,int diff){
        int n=nums.size();
        if(index<0)
        return 0;

        int ans=0;
        for(int i=index-1;i>=0;i--){
            if(nums[index]-nums[i]==diff)
            ans=max(ans,1+solve(nums,i,diff));
        }
        return ans;
    }

    int solveMem(vector<int>& nums,int index,int diff,unordered_map<int,int> dp[]){
        int n=nums.size();
        if(index<0)
        return 0;

        //Step 3 : If already present then return
        // "Kya dp[index] ke andar koi answer exist krta hai??"
        if(dp[index].count(diff))
        return dp[index][diff];

        int ans=0;
        for(int i=index-1;i>=0;i--){
            if(nums[index]-nums[i]==diff)
            ans=max(ans,1+solveMem(nums,i,diff,dp));
        }
        //Step 2 : Store ans in DP
        return dp[index][diff]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {

////////////////////////////////   Recursion   ///////////////////////////
        // int n=nums.size();
        // if(n<=2)
        // return n;

        // int ans=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,solve(nums,i,nums[j]-nums[i])+2);
        //     }
        // }
        // return ans;

////////////////////////////////   Memoisation (DP With Map)  ///////////////////////////
        // int n=nums.size();
        // if(n<=2)
        // return n;

        // //Step 1 : Create Map
        // unordered_map<int,int>dp[n+1];

        // int ans=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,solveMem(nums,i,nums[j]-nums[i],dp)+2);
        //     }
        // }
        // return ans;

////////////////////////////////   Tabulation (DP With Map)  ///////////////////////////
        int n=nums.size();
        if(n<=2)
        return n;

        int ans=0;

        unordered_map<int,int>dp[n+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int count=1;

                //Checking if answer already present
                if(dp[j].count(diff)){
                    //Put it in count
                    count = dp[j][diff];
                }
                dp[i][diff]=1+count;  // 1----> Current element ko include karna hai
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};