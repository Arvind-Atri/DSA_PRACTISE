#include<vector>
#include<unordered_map>




class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // int n=nums.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k) count++;
        //     }
        // }
        // return count;

        int n = nums.size();
        int count = 0;
        vector<int> ps(n, 0);
        unordered_map<int, int> m;
        ps[0] = nums[0];
        // calculating prefix;
        for (int i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (ps[i] == k)
                count++;
            int val = ps[i] - k;
            if (m.find(val) != m.end())
            {
                count += m[val];
            }
            if (m.find(ps[i]) == m.end())
            {
                m[ps[i]] = 0;
            }
            m[ps[i]]++;
        }
        return count;
    }
};
