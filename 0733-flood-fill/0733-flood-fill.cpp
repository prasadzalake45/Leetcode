class Solution {
public:
   void bfs(vector<vector<int>>&image,int sr,int sc,int color,vector<vector<bool>>&visited){
      queue<pair<int,int>>q;
      q.push({sr,sc});
      visited[sr][sc]=true;


      while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
       

        for(int i=0;i<4;i++){
          int newX=x+dx[i];
          int newY=y+dy[i];

          if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size() && image[newX][newY]==image[x][y] && !visited[newX][newY]){
           
            q.push({newX,newY});
            visited[newX][newY]=true;
          }

        }
        image[x][y]=color;

      }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

      int m=image.size();
      int n=image[0].size();
      vector<vector<bool>>visited(m,vector<bool>(n,false));
      bfs(image,sr,sc,color,visited);
      return image;
        
    }
};