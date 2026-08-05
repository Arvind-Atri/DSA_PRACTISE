// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long maxSum = 0, currentSum = 0;
//         unordered_map<int, int> freqMap;

//         // Initial window setup
//         for (int i = 0; i < k; ++i) {
//             currentSum += nums[i];
//             freqMap[nums[i]]++;
//         }

//         // If there are duplicates in the first window, return 0
//         if (freqMap.size() < k) {
//             return 0;
//         }

//         maxSum = currentSum;

//         // Sliding window
//         for (int i = k; i < n; ++i) {
//             currentSum += nums[i] - nums[i - k];
//             freqMap[nums[i]]++;
//             freqMap[nums[i - k]]--;

//             // Remove the element if its frequency becomes 0
//             if (freqMap[nums[i - k]] == 0) {
//                 freqMap.erase(nums[i - k]);
//             }

//             // Check if the current window is valid (no duplicates)
//             if (freqMap.size() == k) {
//                 maxSum = max(maxSum, currentSum);
//             }
//         }

//         return maxSum;
//     }
// };

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long maxSum = 0, currentSum = 0;
        unordered_map<int, int> freqMap;

        // Sliding window approach
        for (int i = 0; i < n; ++i)
        {
            // Add the current element
            currentSum += nums[i];
            freqMap[nums[i]]++;

            // Maintain window size
            if (i >= k)
            {
                currentSum -= nums[i - k];
                freqMap[nums[i - k]]--;

                // Remove the element from map if its frequency becomes 0
                if (freqMap[nums[i - k]] == 0)
                {
                    freqMap.erase(nums[i - k]);
                }
            }

            // Check if the current window is valid (no duplicates)
            if (freqMap.size() == k)
            {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};
