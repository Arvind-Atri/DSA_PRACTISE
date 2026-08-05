class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m;
        int j = 0;
        while (j < n)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

// best Approach

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int idx = m + n - 1;

        int i = m - 1;
        int j = n - 1;

        while (i >= 0 and j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {

                nums1[idx--] = nums1[i--];
            }
            else
            {
                nums1[idx--] = nums2[j--];
            }
        }

        while (j >= 0)
        {
            nums1[idx--] = nums2[j--];
        }
    }
};