class Solution
{
public:
    void fill(vector<vector<char>> &res, int count, int x, int y)
    {
        while (count)
        {
            res[x][y] = '#';
            x--;
            count--;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (box[i][j] == '#')
                    count++;
                else if (box[i][j] == '*')
                {
                    res[j][m - i - 1] = '*';
                    fill(res, count, j - 1, m - i - 1);
                    count = 0;
                }
            }
            if (count > 0)
                fill(res, count, n - 1, m - i - 1);
        }
        return res;
    }
};

// class Solution {
// public:
//     void fill(vector<vector<char>>& res, int count, int x, int y) {
//         // Ensure we don't go out of bounds when filling stones.
//         while (count > 0 && x >= 0) {
//             res[x][y] = '#';
//             x--;  // Move downward in the rotated grid.
//             count--;
//         }
//     }

//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int m = box.size();    // Number of rows in the original box.
//         int n = box[0].size(); // Number of columns in the original box.

//         // Create a rotated grid with dimensions swapped.
//         vector<vector<char>> res(n, vector<char>(m, '.'));

//         for (int i = 0; i < m; ++i) {
//             int count = 0; // Count of stones ('#') in the current row.
//             for (int j = 0; j < n; ++j) {
//                 if (box[i][j] == '#') {
//                     count++;
//                 } else if (box[i][j] == '*') {
//                     // Place the obstacle at the rotated position.
//                     res[j][m - i - 1] = '*';
//                     // Fill stones up to the obstacle.
//                     fill(res, count, j - 1, m - i - 1);
//                     count = 0; // Reset stone count.
//                 }
//             }
//             // Handle remaining stones at the end of the row.
//             if (count > 0) {
//                 fill(res, count, n - 1, m - i - 1);
//             }
//         }

//         return res;
//     }
// };
