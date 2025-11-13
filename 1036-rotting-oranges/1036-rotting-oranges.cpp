class Solution {
public:
    void goToFourDirection(vector<vector<int>>&grid,int i,int j,queue<pair<int,int>>&q,bool& pathToMake,int& fresh){

        int m=grid.size();
        int n=grid[0].size();
        
        //left
        
        if(j-1>=0 && grid[i][j-1]==1){
          q.push({i,j-1});
          grid[i][j-1]=2;  
          pathToMake=true;
            fresh--;
        }

        //right
        if(j+1<n && grid[i][j+1]==1){
            q.push({i,j+1});
            grid[i][j+1]=2;
            pathToMake=true;
              fresh--;
        }

        // up

        if(i-1>=0 && grid[i-1][j]==1){
            q.push({i-1,j});
            grid[i-1][j]=2;
            pathToMake=true;
              fresh--;
        }

        // down

        if(i+1<m && grid[i+1][j]==1){
            q.push({i+1,j});
            grid[i+1][j]=2;
            pathToMake=true;
              fresh--;
        }


        
        



    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;

                }
            }
        }
        int minute=0;
        
        while(!q.empty()){

            int n=q.size();
            bool pathTomake=false;

            for(int i=0;i<n;i++){
               int first=q.front().first;
            int second=q.front().second;
            q.pop();

            goToFourDirection(grid,first,second,q,pathTomake,fresh);
            }

            if(pathTomake==true){
 minute++;
            }

           
            
            


        }
        


         return fresh==0?minute:-1;


     
        
    }
};