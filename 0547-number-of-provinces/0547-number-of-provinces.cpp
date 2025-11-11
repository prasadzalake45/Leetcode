class Solution {
public:


    void dfs(vector<int>adjList[],int node,vector<int>&visited){
        visited[node]=1;

        for(auto neigh:adjList[node]){
            if(!visited[neigh]){
                dfs(adjList,neigh,visited);
            }

        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int node=isConnected.size(); 
        vector<int>adjList[node+1];


        for(int i=0;i<node;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i+1].push_back(j+1);
                }
            }
        }
        

        vector<int>visited(node+1,0);
         int cnt=0;


        for(int i=1;i<node+1;i++){

            if(!visited[i]){
                dfs(adjList,i,visited);
                cnt++;
            }

        }

        return cnt;

        
    }
};