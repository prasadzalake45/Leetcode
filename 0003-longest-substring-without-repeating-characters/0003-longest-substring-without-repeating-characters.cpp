class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char>seti;

        int i=0;
        int j=0;
        int n=s.size();
        int maxi=0;
        int len=0;

        while(j<n){
            if(seti.find(s[j])==seti.end()){

                seti.insert(s[j]);
                int len=seti.size();
                
                maxi=max(maxi,len);
                j++;
            }

            else{
              
                seti.erase(s[i]);
                i++;
              


            }
        }

        return maxi;

        
    }
};