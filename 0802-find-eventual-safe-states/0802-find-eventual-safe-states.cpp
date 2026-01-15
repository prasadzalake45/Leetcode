class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        // i have to convert this into indree to so that can use topo+bfs
        int node = graph.size();
        vector<vector<int>> adjList(node);

        vector<int> indree(node, 0);

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int v = graph[i][j];
                adjList[v].push_back(i);
                indree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < indree.size(); i++) {
            if (indree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto neigh : adjList[node]) {
                indree[neigh]--;

                if (indree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};