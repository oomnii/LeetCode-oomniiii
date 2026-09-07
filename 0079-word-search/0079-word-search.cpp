class Solution {
public:
    int m;
    int n;
    int sz;
    bool check(vector<vector<char>>& board, string word,int i,int j,int index){
        if(index==sz) return true;

        // DO:
        char temp = board[i][j];
        board[i][j] = '#'; 

        // EXPLORE:  
        //up:
        bool up = false;
        if(i-1>=0 && board[i-1][j] == word[index]){
            up = check(board,word,i-1,j,index+1);
        }
        //down:
        bool down = false;
        if(i+1<m && board[i+1][j] == word[index]){
            down = check(board,word,i+1,j,index+1);
        }
        //left:
        bool left = false;
        if(j-1>=0 && board[i][j-1] == word[index]){
            left = check(board,word,i,j-1,index+1);
        }
        //right:
        bool right = false;
        if(j+1<n && board[i][j+1] == word[index]){
            right = check(board,word,i,j+1,index+1);
        }

        // UNDO: 
        board[i][j] = temp;
        
        return  up || down || right || left;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        sz = word.length();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){       
                    if(check(board,word,i,j,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};