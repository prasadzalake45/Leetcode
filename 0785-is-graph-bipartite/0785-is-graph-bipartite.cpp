class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph ,vector<int>& visited) {
        visited[node] = 0;

        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            auto nod = q.front();
            q.pop();

            for (auto it : graph[nod]) {

                if (visited[it] == -1) {
                     visited[it] = !visited[nod];
                    q.push(it);
                   
                } else if (visited[it] != -1) {
                    if (visited[it] == visited[nod]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int m = graph.size();
        int n = graph[0].size();
        if (m == 0) {
            return true;
        }
      

        vector<int> visited(m, -1);

        for (int i = 0; i < m; i++) {
            if (visited[i] == -1) {
                if (bfs(i, graph, visited) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};