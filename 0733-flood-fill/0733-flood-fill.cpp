class Solution {
public:
   void bfs(vector<vector<int>>&image,int sr,int sc,int color){
      queue<pair<int,int>>q;
      q.push({sr,sc});
      int oldColor=image[sr][sc];

      if(oldColor==color){
        return;
      }
      image[sr][sc]=color;
     
      


      while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
       

        for(int i=0;i<4;i++){
          int newX=x+dx[i];
          int newY=y+dy[i];

          if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size() && image[newX][newY]==oldColor){
            image[newX][newY]=color;
            q.push({newX,newY});
           
          }

        }
        

      }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

      int m=image.size();
      int n=image[0].size();
     
      bfs(image,sr,sc,color);
      return image;
        
    }
};