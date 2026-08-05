class Solution
{
public:
#define p pair<int, pair<int, int>>
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // Initial condition is necessary because we cannot go back and forth to increase waiting time
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<p, vector<p>, greater<>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int time = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            if (i == m - 1 && j == n - 1)
                return time;

            for (auto &dir : directions)
            {
                int r = i + dir[0];
                int c = j + dir[1];
                if (r < 0 || c < 0 || r >= m || c >= n)
                    continue;

                int wait = (grid[r][c] - time) % 2 == 0;
                int newTime = max(grid[r][c] + wait, time + 1);
                if (newTime < result[r][c])
                {
                    result[r][c] = newTime;
                    pq.push({newTime, {r, c}});
                }
            }
        }
        return -1;
    }
};