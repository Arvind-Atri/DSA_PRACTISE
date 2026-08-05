class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        long long Sum = 0;
        int negCount = 0;
        int minNum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Sum += abs(matrix[i][j]);
                minNum = min(minNum, abs(matrix[i][j]));

                if (matrix[i][j] < 0)
                    negCount++;
            }
        }
        if (negCount % 2 == 0)
        {
            return Sum;
        }
        else
        {
            return Sum - 2 * minNum;
        }
    }
};