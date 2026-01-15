class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adjList(n+1);

        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjList[u].push_back({v, wt});
        }

       priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> q;

        q.push({0, k});

        vector<int> distance(n+1, 1e9);

        distance[k] = 0;

        while (!q.empty()) {

            auto [dist, node] = q.top();
            q.pop();

            for (auto [neigh, wgt] : adjList[node]) {

                if(distance[neigh] > distance[node] + wgt) {
                    distance[neigh] = distance[node] + wgt;
                    q.push({distance[neigh],neigh});
                }
            }
        }

    
        int maxi = 0;

        for (int i = 1; i <= n; i++) {
                        if (distance[i] == 1e9) return -1;

            maxi = max(maxi, distance[i]);
        }

        return maxi;
    }
};