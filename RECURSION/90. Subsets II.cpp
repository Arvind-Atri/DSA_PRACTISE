class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<int> output,
               vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(output);
            return;
        }

        // INCLUDE

        output.push_back(nums[index]);
        solve(nums, index + 1, output, ans);
        output.pop_back();
        // EXCLUDE
        int i = index + 1;
        while (i < nums.size() && nums[i] == nums[i - 1])
            i++;

        solve(nums, i, output, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // int index=0;
        sort(nums.begin(), nums.end());
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums, 0, output, ans);
        return ans;
    }
};