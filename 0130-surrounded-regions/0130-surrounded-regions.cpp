class Solution {
public:

   void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&visited){

     
    visited[i][j]=1;

    int m = board.size();
    int n = board[0].size();
    
     
 
      
     // left
     if(j-1>=0 && board[i][j-1]=='O' && !visited[i][j-1]){
 
         dfs(i,j-1,board,visited);
      }

      // right
      
      if(j+1<n && board[i][j+1]=='O' && !visited[i][j+1]){
        
         dfs(i,j+1,board,visited);

      }

      //up 

      
      if(i-1>=0 && board[i-1][j]=='O' && !visited[i-1][j]){
        
         dfs(i-1,j,board,visited);
        
      }

      // down
      
      if(i+1<m && board[i+1][j]=='O' && !visited[i+1][j]){
     
        dfs(i+1,j,board,visited);
      }
   }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

       vector<vector<int>>visited(m,vector<int>(n,0));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1)&& board[i][j]=='O'){
                    dfs(i,j,board,visited);
                }
            }
        }


       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                board[i][j]='X';
            }
        }
       }
        
    }
};