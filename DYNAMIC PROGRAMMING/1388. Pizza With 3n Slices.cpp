class Solution
{
private:
    int solveMem(int sindex, int eindex, vector<int> &slices,
                 int n, vector<vector<int>> &dp)
    {
        if (n == 0 || sindex > eindex)
            return 0;

        if (dp[sindex][n] != -1)
            return dp[sindex][n];

        int take = slices[sindex] + solveMem(sindex + 2, eindex, slices, n - 1, dp);
        int nottake = 0 + solveMem(sindex + 1, eindex, slices, n, dp);

        return dp[sindex][n] = max(take, nottake);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int case1 = solveMem(0, k - 2, slices, k / 3, dp1);
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solveMem(1, k - 1, slices, k / 3, dp2);
        return max(case1, case2);
    }
};

class Solution
{
private:
    int solveTab(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k, 0));

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp1[index + 2][n - 1];
                int nottake = 0 + dp1[index + 1][n];

                dp1[index][n] = max(take, nottake);
            }
        }

        int case1 = dp1[0][k / 3];

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp2[index + 2][n - 1];
                int nottake = 0 + dp2[index + 1][n];

                dp2[index][n] = max(take, nottake);
            }
        }

        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        return solveTab(slices);
    }
};