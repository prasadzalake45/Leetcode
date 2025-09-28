class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        unordered_map<char,int>mp;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(!mp.empty() && mp.find(s[j])!=mp.end()){
                    mp.clear();
                    break;


                }
                else if(mp.find(s[j])==mp.end()){
                    mp[s[j]]=j;
                }
                 
                maxi=max(maxi,j-i+1);


            }
        }

        if(maxi==INT_MIN){
            return 0;
        }

        return maxi;
        
    }
};