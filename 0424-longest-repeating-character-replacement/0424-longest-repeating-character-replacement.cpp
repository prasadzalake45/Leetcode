class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();

        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int maximum=0;

        while(j<n){

            mp[s[j]]++;
            int maxi=0;
            for(auto it:mp){
                maxi=max(maxi,it.second);

            }

            int req=(j-i+1)-maxi;

            if(req<=k){
                maximum=max(maximum,j-i+1);
            }

             
        if(req>k){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        
        j++;



        }
        return maximum;
        
    }
};