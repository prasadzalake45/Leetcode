class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j,
            vector<vector<int>>&visited){


        visited[i][j] = 1;

        if (mat[i][j] == '0') {
            return ;
        }

        // left

        if (j - 1 >= 0 && mat[i][j-1] == '1' && !visited[i][j-1]) {
            dfs(mat, i, j - 1, visited);
        }

        // right
        if (j + 1 < mat[0].size() && mat[i][j+1] =='1'&& !visited[i][j+1]) {
            dfs(mat, i, j + 1,visited);
        }

        // up
        if (i - 1 >= 0 && mat[i-1][j] == '1'&& !visited[i-1][j]) {
            dfs(mat, i - 1, j, visited);
        }

        // down
        if (i + 1 < mat.size() && mat[i+1][j] == '1' && !visited[i+1][j]) {
            dfs(mat, i + 1, j, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};