class Solution {
public:

   int bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){

    queue<pair<int,int>>q;
    q.push({row,col});
    visited[row][col]=2;
    int cnt=0;
    

    while(!q.empty()){

      int size=q.size();
       bool taken=false;


      for(int i=0;i<size;i++){

      
      auto [x,y]=q.front();
      q.pop();
      
    
      int dx[]={0,1,0,-1};
      int dy[]={1,0,-1,0};
    

      for(int i=0;i<4;i++){
       
        int newX=x+dx[i];
        int newY=y+dy[i];

        if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]==1 && visited[newX][newY]!=2){
          
          visited[newX][newY]=2;
          q.push({newX,newY});
          taken=true;
          
        }
      }
      

      }

    if(taken){
      cnt++;
    }



    }
    return cnt;


   }
    int orangesRotting(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<int>>visited=grid;
      int ans=0;

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==2){
            ans=bfs(i,j,grid,visited);
          }
        }
      }

      for(int i=0;i<visited.size();i++){
        for(int j=0;j<visited[0].size();j++){
          if(visited[i][j]==1){
            return -1;
          }
          // cout<<visited[i][j]<<" ";
        }
        // cout<<endl;
      }

      return ans;
       
    }
};