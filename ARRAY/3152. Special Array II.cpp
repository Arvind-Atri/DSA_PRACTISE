class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefix_sum(n, 0); // Initialize prefix array with size n
        prefix_sum[0] = 1;
        // Calculate the prefix array
        for (int i = 1; i < n; i++)
        {
            if ((nums[i] & 1) == (nums[i - 1] & 1))
            {
                prefix_sum[i] = 1;
            }
            else
            {
                prefix_sum[i] = 1 + prefix_sum[i - 1];
            }
        }

        vector<bool> ans; // Result vector

        // Process the queries
        for (auto &q : queries)
        {
            int start = q[0], end = q[1];

            int Count = end - start + 1;
            if (prefix_sum[end] >= Count)
                ans.push_back(true);
            else
                ans.push_back(false);
            // ans.push_back(specialCount == 0);
        }

        return ans; // Return the result
    }
};