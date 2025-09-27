class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();


        unordered_map<char,int>mp;

        
        int maxi=INT_MIN;

        int i=0;
        int j=0;

        while(j<n){

            if(!mp.empty() && mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }

            mp[s[j]]=j;
            maxi=max(maxi,j-i+1);
            j++;


        }

        if(maxi==INT_MIN){
            return 0;
        }

        return maxi;



        
    }
};