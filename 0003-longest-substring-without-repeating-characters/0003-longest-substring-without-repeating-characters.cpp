class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.size();

      if(n==0){
        return 0;
      }

      int i=0;
      int j=0;


      unordered_map<char,int>mp;

      int maxi=1;

      while(j<n){

        if(mp.find(s[j])!=mp.end()){

          
          i=max(i,mp[s[j]]+1);
          




        }

        mp[s[j]]=j;
        maxi=max(maxi,j-i+1);
        j++;
        




      }

      return maxi;

      
           
    }
};