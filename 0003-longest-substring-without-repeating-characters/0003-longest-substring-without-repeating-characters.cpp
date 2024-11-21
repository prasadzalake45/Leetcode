class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        if(n==0){
            return 0;
        }
        

        set<char>mp;

        int i=0;
        int j=0;

        int maxi=1;

        while(j<n){

            if(mp.empty()){
                mp.insert(s[j]);
                j++;
                
            }

            else if(mp.count(s[j])==0){
                mp.insert(s[j]);
                maxi=max(maxi,j-i+1);
                 j++;
            }

            else{
                mp.erase(s[i]);
                i++;
            }
           


        }

        return maxi;
    }
};