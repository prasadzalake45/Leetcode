class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>>&dp) {

        if (i > m || j > n) {
            return 0;
        }

         if(dp[i][j]!=-1){
            return dp[i][j];
        }


        if (i == m - 1 && j == n - 1) {

            return 1;
        }

       
        return dp[i][j]=helper(m, n, i, j + 1,dp) + helper(m, n, i + 1, j,dp);
    }
    int uniquePaths(int m, int n) {

        int i = 0;
        int j = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return helper(m, n, i, j, dp);
        
    }
};