class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word,int i,int j,int idx){
        int m=board.size();
        int n=board[0].size();
        if(idx==word.size()){
            return true;
        }

        if(i<0||j<0 ||i>=m||j>=n ||board[i][j]!=word[idx]){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='$';

        bool found=dfs(board,word,i+1,j,idx+1)||dfs(board,word,i-1,j,idx+1)||dfs(board,word,i,j+1,idx+1)||dfs(board,word,i,j-1,idx+1);

        board[i][j]=temp;

        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {

        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }

        return false;
        
    }
};