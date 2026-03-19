class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        // prefX
        vector<vector<int>> prefX(row, vector<int>(col, 0));
        vector<vector<int>> prefY(row, vector<int>(col, 0));
        // prefX
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                int left = (j - 1 >= 0) ? prefX[i][j - 1] : 0;
                int top = (i - 1 >= 0) ? prefX[i - 1][j] : 0;
                int diagonal =
                    (i - 1 >= 0 && j - 1 >= 0) ? prefX[i - 1][j - 1] : 0;

                int current = (grid[i][j] == 'X') ? 1 : 0;

                prefX[i][j] = left + top - diagonal + current;
            }
        }
       // prefY
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                int left = (j - 1 >= 0) ? prefY[i][j - 1] : 0;
                int top = (i - 1 >= 0) ? prefY[i - 1][j] : 0;
                int diagonal =
                    (i - 1 >= 0 && j - 1 >= 0) ? prefY[i - 1][j - 1] : 0;

                int current = (grid[i][j] == 'Y') ? 1 : 0;

                prefY[i][j] = left + top - diagonal + current;
            }
        }
        
        int ginle=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(prefX[i][j]==prefY[i][j] && prefX[i][j]!=0 && prefY[i][j]!=0){
                    ginle++;
                }
            }
        }

        return ginle;
    }
};