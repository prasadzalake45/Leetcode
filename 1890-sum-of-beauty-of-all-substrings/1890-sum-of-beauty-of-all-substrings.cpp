class Solution {
public:
    int beautySum(string s) {

        

        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                int maxi=INT_MIN;
                int mini=INT_MAX;

                for(auto it:mp){
                    if(it.second>maxi){
                        maxi=it.second;
                        
                    }

                    if(it.second<mini){
                        mini=it.second;
                    }
                }

                int result=maxi-mini;
                ans+=result;






            }
            mp.clear();

        }
        return ans;
    }
};