class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adjL(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }


        int res=0;

        vector<int>visited(n,false);

        for(int i=0;i<n;i++){

            queue<int>q;
            q.push(i);
            visited[i]=true;
            vector<int>component;

            while(!q.empty()){
                auto u=q.front();
                component.push_back(u);
                q.pop();

                for(auto it:adjL[u]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=true;
                    }
                }


            }

            int k=component.size();

            int cnt=0;

            for(auto u:component){
                cnt+=adjL[u].size();
            }

            if(cnt==k*(k-1)){
                res++;
            }














        }
        return res;

        
    }
};