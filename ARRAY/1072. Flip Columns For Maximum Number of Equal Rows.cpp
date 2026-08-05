class Solution
{
public:
    // int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    //     int m=matrix.size();
    //     int n=matrix[0].size();

    //     int maxRows=0;
    //     for(auto & currRow:matrix){
    //         vector<int>inverted(n);

    //         for(int col=0;col<n;col++){
    //             inverted[col]=currRow[col]==0?1:0; //flip -> 1-currRow[col];

    //         }
    //         int cnt=0;
    //         for(auto &row:matrix){
    //             if(row==currRow || row== inverted) cnt++;
    //         }

    //         maxRows=max(maxRows,cnt);
    //     }
    //     return maxRows;
    // }

    // APPROACH 2
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> mp;
        int m = matrix.size();
        int n = matrix[0].size();

        for (auto &row : matrix)
        {
            string rowNature = "";
            int firstVal = row[0];
            for (int col = 0; col < n; col++)
            {
                rowNature += row[col] == firstVal ? "S" : "D";
            }
            mp[rowNature]++;
        }
        int maxRows = 0;
        for (auto &it : mp)
        {
            maxRows = max(maxRows, it.second);
        }
        return maxRows;
    }
};