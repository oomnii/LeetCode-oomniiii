class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &board,int row,int col,int n){
        // column:
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }

        // upper left Diagonal:
        for(int i=row-1,j=col-1 ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q') return false;
        }

        // upper right Diagonal:
        for(int i=row-1,j=col+1 ; i>=0 && j<n ; i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                // DO:
                board[row][col] = 'Q';

                // Explore:
                solve(board,row+1,n);

                // Undo:
                board[row][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};