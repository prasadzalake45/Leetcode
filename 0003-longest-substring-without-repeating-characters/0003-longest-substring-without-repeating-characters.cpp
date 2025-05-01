class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        if(n==0){
            return 0;
        }

        int i=0;
        int j=0;
        int maxi=1;

        unordered_map<char,int>mp;

        while(j<n){


            while(mp.find(s[j])!=mp.end()){
                mp[s[i]]--;

                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }

            mp[s[j]]++;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};