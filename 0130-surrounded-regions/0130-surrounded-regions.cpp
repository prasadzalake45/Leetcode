class Solution {
public:
   void helper(vector<vector<char>>& board,queue<pair<int,int>>&q){
    

    while(!q.empty()){
      auto [x,y]=q.front();
      q.pop();

      board[x][y]='#';

      int dx[]={0,1,0,-1};
      int dy[]={1,0,-1,0};

      for(int i=0;i<4;i++){

        int newX=x+dx[i];
        int newY=y+dy[i];

        if(newX>=0 && newX<board.size() && newY>=0 && newY<board[0].size()){
          if(board[newX][newY]=='O'){
            q.push({newX,newY});
            board[newX][newY]='#';
            

          }
        }

      }
    }

   }
    void solve(vector<vector<char>>& board) {

      int m=board.size();
      int n=board[0].size();
      queue<pair<int,int>>q;

      // row first and last
      for(int j=0;j<n;j++){
        if(board[0][j]=='O'){
          q.push({0,j});
        }

        if(board[m-1][j]=='O'){
          q.push({m-1,j});
        }
      }


      //column  first and last

       for(int i=1;i<m-1;i++){
        if(board[i][0]=='O'){
          q.push({i,0});
        }

        if(board[i][n-1]=='O'){
          q.push({i,n-1});
        }
      }

      helper(board,q);


    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(board[i][j]=='#'){
          board[i][j]='O';
        }
        else{
          board[i][j]='X';

        }
      }
    }



     
        
    }
};