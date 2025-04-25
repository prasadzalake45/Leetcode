class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        if(n==0){
            return 0;
        }

        int i=0;
        int j=0;
        unordered_set<int>mp;
        int maxi=1;

        while(j<n){

             while(mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
                

            }
            maxi=max(maxi,j-i+1);
            mp.insert(s[j]);
            j++;





        }
        return maxi;
        
    }
};