class Solution {
public:
    int characterReplacement(string s, int k) {
         
    int n=s.size();
    
    int i=0;
    int j=0;
    int maxi=INT_MIN;
    int cnt=0;

    unordered_map<char,int>mp;
    while(j<n){

        mp[s[j]]++;

        cnt=max(cnt,mp[s[j]]);


        int replacementOption=(j-i+1)-cnt;

        if(replacementOption>k){
              mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;

        }

        maxi=max(maxi,j-i+1);

        j++;




        
        
  

           
      




    }

    return maxi;

   

       




        
    }
};