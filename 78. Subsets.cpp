

// TODO:DO it With Bit Manipulation



class Solution {

private:
    void solve(vector<int>&nums,int index,vector<int>output,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        // EXCLUDE
        solve(nums,index+1,output,ans);

        //INCLUDE

        output.push_back(nums[index]);
        solve(nums,index+1,output,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int>output;
        vector<vector<int>>ans;
        solve(nums,index,output,ans);
        return ans;
    }
};