class Solution
{

    bool issafe(int row, int col, char val, vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == val)
            { // row check
                return false;
            }
            if (board[i][col] == val)
            { // col check
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                {
                    for (int val = '1'; val <= '9'; val++)
                    {
                        if (issafe(row, col, val, board))
                        {
                            board[row][col] = val;
                            bool solPossible = solve(board);
                            if (solPossible)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true; // for fully filled board
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};