class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjMatrix, vector<int>& visited,
             vector<int>& pathVisited, vector<int>&answer) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto neigh : adjMatrix[node]) {
            if (!visited[neigh]) {
                if(dfs(neigh, adjMatrix, visited, pathVisited,answer)==true){
                    return true;
                };
            }
            else if (pathVisited[neigh]) {
                return true;
            }
      
        }

        answer.push_back(node);
        pathVisited[node] = 0;
        return false;    
        }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMatrix(numCourses);
        vector<int> answer;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjMatrix[u].push_back(v);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if ((!visited[i])) {
                if(dfs(i, adjMatrix, visited, pathVisited, answer)==true){
                    return {};
                }
            }
        }

        

        return answer;
    }
};