class Solution
{
private:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        // Base Condn->
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        { // iterate from index to nums.length()

            swap(nums[index], nums[i]);
            solve(nums, index + 1, ans);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};