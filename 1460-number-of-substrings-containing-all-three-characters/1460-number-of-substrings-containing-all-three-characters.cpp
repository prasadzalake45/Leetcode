class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();


        int i=0;
        int j=0;
  

        unordered_map<char,int>mp;

        int cnt=0;
        while(j<n){

            mp[s[j]]++;


            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                cnt+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;


        }

        return cnt;
        
    }
};