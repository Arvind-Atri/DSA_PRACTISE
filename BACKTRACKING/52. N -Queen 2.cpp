class Solution {
    int N;
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col){
        //col
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // left upper diagnol
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // right upper diagnol
        for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        
        return true;
    }
    
    void solve(vector<string> &board, int row){
        if(row >= N){
            res.push_back(board);
            return;
        }
        
        for(int col = 0; col < N; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                // cout<<"Entered"<<row<<'+'<<col<<endl;
                solve(board, row + 1);
                // cout<<"Exited"<<row<<'+'<<col<<endl;
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
         N = n;
        vector<string> board(n, string(n, '.'));
        
        solve(board, 0);
        
        return res.size();
    }
};