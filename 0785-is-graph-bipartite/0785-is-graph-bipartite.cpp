class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph ,vector<int>& visited) {
     

       for(auto it:graph[node]){
          if(visited[it]==-1){
            visited[it]=!visited[node];
           if (!dfs(it, graph, visited)) {
                    return false;
                }
          }
          else if(visited[it]!=-1){
            if(visited[it]==visited[node]){
                return false;
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
                visited[i]=0;
                if (dfs(i, graph, visited) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};