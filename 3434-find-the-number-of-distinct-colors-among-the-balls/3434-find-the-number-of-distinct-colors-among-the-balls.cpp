class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;

        vector<int>ans;

        unordered_map<int,int>mp2;

        for(auto it:queries){
            int ball=it[0];
            int color=it[1];

            if(mp2.find(ball)!=mp2.end()){
                int old=mp2[ball];
                mp[old]--;

                if(mp[old]==0){
                    mp.erase(old);
                }
            }

          mp2[ball]=color;

            mp[color]++;

            ans.push_back(mp.size());
        }

        return ans;
    }
    
};