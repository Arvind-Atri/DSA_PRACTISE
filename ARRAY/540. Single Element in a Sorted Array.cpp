class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0;

        int n = nums.size();
        int e = n - 1;

        if (n == 1)
            return nums[0];

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mid == 0 and nums[0] != nums[1])
                return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[mid];

            if (nums[mid - 1] != nums[mid] and nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid % 2 == 0)
            { // even
                if (nums[mid - 1] == nums[mid])
                    e = mid - 1; // left
                else
                    s = mid + 1; // right
            }
            else
            { // odd
                if (nums[mid - 1] == nums[mid])
                    s = mid + 1; // right
                else
                    e = mid - 1; // left
            }
        }
        return -1;
    }
};