class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<char>>grid(m,vector<char>(n,'U'));

        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        for(auto guard:guards){
            grid[guard[0]][guard[1]]='G';
        }

        for(auto wall:walls){
            grid[wall[0]][wall[1]]='W';
        }

        for(auto gr:guards){
            int x=gr[0];
            int y=gr[1];

            for(auto d:dir){
                int dx=x,dy=y;

                while(true){
                    dx+=d[0];
                    dy+=d[1];

                    if(dx<0 || dx>=m || dy<0 || dy>=n || grid[dx][dy]=='G' || grid[dx][dy]=='W'){
                        break;
                    }

                    if(grid[dx][dy]=='U'){
                        grid[dx][dy]='V';
                    }

                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='U'){
                    cnt++;
                }
            }
        }

        return cnt;


        
    }
};