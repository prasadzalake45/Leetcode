class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        if(n==0){
            return 0;
        }

        int maxi=0;

        for(int i=0;i<n;i++){

            unordered_set<char>mp;

            for(int j=i;j<n;j++){

                if(mp.find(s[j])!=mp.end()){
                   
                    break;

                }
                 mp.insert(s[j]);
                 maxi=max(maxi,j-i+1);
               

            }
        }

        return maxi;
        
    }
};