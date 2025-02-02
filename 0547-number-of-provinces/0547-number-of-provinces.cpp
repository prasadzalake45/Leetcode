class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjList, int n, vector<int>& vis) {

        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            for (auto it : adjList[start]) {

                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjList(n);
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int prov = 0; prov < n; prov++) {
            if (!visited[prov]) {
                bfs(prov, adjList, n, visited);
                cnt++;
            }
        }

        return cnt;
    }
};