class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjList(numCourses);

        for ( auto it : prerequisites) {

            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
        
            indegree[v] += 1;
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        if (q.empty()) {
            return false;
        }

        stack<int>st;


        while (!q.empty()) {
            int node = q.front();
            q.pop();
            st.push(node);
            

            for (auto it:adjList[node]){

                
                    indegree[it]--;

                    if(indegree[it]==0){
                        q.push(it);
                    }
                

            }
        }


        if(st.size()==numCourses){
            return true;
        }


        return false;
    }
};