class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();

        unordered_map<char,int>mp;

        int i=0;
        int j=0;
        int cnt=0;

        while(j<n){

            mp[s[j]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                cnt+=(n-j);
                mp[s[i]]--;

                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;

            }
            j++;
        }

        return cnt;
        
    }
};