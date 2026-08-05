// Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int target = 0;
        sort(nums.begin(), nums.end());

        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return output;
    }
};