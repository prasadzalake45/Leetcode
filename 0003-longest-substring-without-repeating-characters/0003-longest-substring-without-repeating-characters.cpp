class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        if(n==0){
            return 0;
        }

        int i=0;
        int j=0;

        unordered_set<char>mp;
        int maxi=INT_MIN;
        while(j<n){

            if(mp.empty()){
                mp.insert(s[j]);
                maxi=max(maxi,j-i+1);
                
                

                j++;
            }
            else if(mp.count(s[j])==0){
                maxi=max(maxi,j-i+1);
                mp.insert(s[j]);
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