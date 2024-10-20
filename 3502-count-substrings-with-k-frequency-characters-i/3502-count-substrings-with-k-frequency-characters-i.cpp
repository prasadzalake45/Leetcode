class Solution {
public:

   bool ischeck(unordered_map<char,int>&mp,string s,int k){
     

     for(auto it:mp){
        if(it.second>=k){
            return true;
        }
     }

     return false;
   }
    int numberOfSubstrings(string s, int k) {

        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();

        int cnt=0;

        while(j<n){
            mp[s[j]]++;

            while(ischeck(mp,s,k)==true){

                cnt+=n-j;

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