class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<int>ans;

        for(int i=0;i<n;i++){
            mp[s[i]]=i;

        }

        int mapIndex=0;
        int partStart=0;

        for(int i=0;i<n;i++){
            mapIndex=max(mapIndex,mp[s[i]]);

            if(i==mapIndex){
                ans.push_back(mapIndex-partStart+1);
                partStart=i+1;
            }
        }

        return ans;
        
    }
};