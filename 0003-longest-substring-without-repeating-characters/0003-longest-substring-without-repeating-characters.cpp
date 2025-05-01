class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        int maxi=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;

            for(int j=i;j<n;j++){

                if(mp.find(s[j])!=mp.end()){
                    maxi=max(maxi,j-i);
                    break;
                }
                else{
                   
                    mp[s[j]]++;
                   
                }

            }

              maxi=max(maxi,(int)mp.size());
        
        }
        
      
        return maxi;
        
    }
};