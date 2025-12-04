class Solution {
public:
 bool dfs(int node,vector<vector<int>>&adjMatrix,vector<int>&visited,vector<int>&pathVisited){
      visited[node]=1;
      pathVisited[node]=1;
      
      for(auto neigh:adjMatrix[node]){
          if(!visited[neigh]){
             if(dfs(neigh,adjMatrix,visited,pathVisited)==true){
                 return true;
             }
        }
        else if(pathVisited[neigh]){
            return true;
        }
      }


      pathVisited[node]=0;
      
      
      return false;
  }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    
    vector<vector<int>>adjMatrix(numCourses);
        
        
        
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjMatrix[u].push_back(v);
        }
        
        vector<int>visited(numCourses,0);
        vector<int>pathVisited(numCourses,0);

        
        for(int i=0;i<numCourses;i++){
            if((!visited[i])){
                if(dfs(i,adjMatrix,visited,pathVisited)==true){
                    return false;
                }
            }
        }
        return true;

    }
};