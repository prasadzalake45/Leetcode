class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();

        if(n==0){
            return 0;
        }

        int maxi=1;

        unordered_set<int>mp;

        // for(int i=0;i<n;i++){
        //     if(mp.find(s[i])!=mp.end()){
        //         int ans=mp.size();
        //         maxi=max(maxi,ans);
        //         mp.clear();

        //     }
            
        //      mp.insert(s[i]);
        
        // }
        // maxi=max(maxi,(int)mp.size());

        int i=0;
        int j=0;

        while(j<n){
            while(mp.find(s[j])!=mp.end()){
                maxi=max(maxi,(int)mp.size());
                mp.erase(s[i]);
                i++;
                
            }
            mp.insert(s[j]);
            j++;
        }

        maxi=max(maxi,(int)mp.size());

        return maxi;


        
    }
};