class Solution {
public:

    void dfs(vector<vector<int>>&graph,vector<vector<int>>&result,int start,int end,vector<int>&path){

       path.push_back(start);


        if(start==end){
            result.push_back(path);
        }
        else{

            for(auto it:graph[start]){
                dfs(graph,result,it,end,path);
            }

        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {      
        
        int n=graph.size();
     
        vector<vector<int>>result;
        vector<int>path;
        int start=0;
        int end=n-1;
        dfs(graph,result,start,end,path);
        return result;
    

    }
};