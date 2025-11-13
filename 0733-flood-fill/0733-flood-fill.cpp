class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        
        int originalColor=image[sr][sc];
        if (originalColor == color) return image;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;


        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==originalColor) {
                    q.push({nx, ny});
                    image[nx][ny] = color;
                }
            }
        }

        return image;
    }
};