class Solution {
public:

    void bfs(vector<vector<int>>&dist,queue<pair<int,int>>&q){

      while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0;i<4;i++){

          int newX=x+dx[i];
          int newY=y+dy[i];

          if(newX>=0 && newX<dist.size() && newY>=0 && newY<dist[0].size()){
            if(dist[newX][newY]==-1){
              dist[newX][newY]=dist[x][y]+1;
              q.push({newX,newY});
            }
          }

        }
      }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> dist(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});

                } else {
                    dist[i][j] = -1;
                }
            }
        }



        bfs(dist,q);

        return dist;




        
      
    }
};