class Solution {
public:
    int helper(vector<vector<int>>& grid, queue<pair<int, int>>& q,
               int& fresh) {
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            bool happen = false;

            for (int i = 0; i < size; i++) {

                auto [x, y] = q.front();
                q.pop();

                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};

                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                        newY < grid[0].size() && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                        happen = true;
                    }
                }
            }

            if (happen) {
                cnt++;
            }
        }

        return fresh == 0 ? cnt : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        return helper(grid, q, fresh);
    }
};