class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>&dp) {
        int row = matrix.size();
        int col = matrix[0].size();

        if (i < 0 || i >= row || j < 0 || j >= col) {
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // left

        int left = 1;

        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            left = 1 + helper(matrix, i - 1, j,dp);
        }

        int right = 1;

        if (i + 1 < row && matrix[i + 1][j] > matrix[i][j]) {
            right = 1 + helper(matrix, i + 1, j,dp);
        }

        int up = 1;

        if (j - 1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            up = 1 + helper(matrix, i, j - 1,dp);
        }

        int down = 1;

        if (j + 1 < col && matrix[i][j + 1] > matrix[i][j]) {
            down = 1 + helper(matrix, i, j + 1,dp);
        }

        return dp[i][j]=max({left,right,up,down});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int maxi = INT_MIN;

        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int result=helper(matrix,i,j,dp);
                maxi=max(maxi,result);
            }
        }

        return maxi;
    }
};