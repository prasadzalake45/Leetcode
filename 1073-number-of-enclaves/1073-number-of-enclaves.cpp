class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]=2;
        //left
        if(j-1>=0 && grid[i][j-1]==1){
            dfs(i,j-1,grid);
        }
        

        //right
         if(j+1<n && grid[i][j+1]==1){
            dfs(i,j+1,grid);
        }

        //up 
        if(i-1>=0 && grid[i-1][j]==1){
            dfs(i-1,j,grid);
        }

        // down

        if(i+1<m && grid[i+1][j]==1){
            dfs(i+1,j,grid);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
 
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }


       int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;

        
    }
};