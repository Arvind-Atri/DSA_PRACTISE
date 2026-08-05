class Solution
{
public:
    int pivot(vector<int> &arr, int n)
    {
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;
            // cout<<start<<mid<<end<<endl;
            if (arr[mid] > arr[0])
            {

                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
        // return-1;
    }

    int binarySearch(vector<int> &arr, int s, int n, int target)
    {
        int start = s;
        int end = n - 1;
        while (start <= end)
        {
            // s+e/2-s/2=>s+(e-s)/2
            // s/2+e-e/2=>e+(s-e)/2   //use any for optimization
            int mid = (start + end) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << "not found";
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int x = pivot(nums, n);
        if (target >= nums[x] && target <= nums[n - 1])
        {
            return binarySearch(nums, x, n, target);
        }
        else
        {
            return binarySearch(nums, 0, x, target);
        }
    }
};