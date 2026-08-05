class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n, 0);
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }
        // find champ
        int champ;
        int champCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                champ = i;
                champCount++;
                if (champCount > 1)
                {
                    return -1;
                }
            }
        }
        return champ;
    }
};