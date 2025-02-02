class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, int n, vector<int>& vis) {

       vis[node]=1;

       for(auto it:adjList[node]){
        if(!vis[it]){
            dfs(it,adjList,n,vis);
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
                dfs(prov, adjList, n, visited);
                cnt++;
            }
        }

        return cnt;
    }
};