class Solution {
public:

bool isSafe(int row,int col,vector<string>board,int n){

    // 1) up col

    for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    // 2) left diagonal

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }

    }
    // 3)right diagonal

    for(int i=row-1,j=col+1;i>=0&& j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }


    }

    return true;

}
void solve(int row,int col,vector<string>&board,vector<vector<string>>&result,int n){
    if(row==n){
        result.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,col,board,result,n);
            board[row][col]='.';
        }

    }

}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>result;

    vector<string>board(n,string(n,'.'));

    solve(0,0,board,result,n);

    return result;
        
    }
};