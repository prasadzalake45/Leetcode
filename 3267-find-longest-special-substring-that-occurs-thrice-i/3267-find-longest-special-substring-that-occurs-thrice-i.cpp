class Solution {
public:
    int maximumLength(string s) {

         int n=s.size();

        map<pair<char,int>,int>mp;

        for(int i=0;i<n;i++){
            char ch=s[i];
            int l=0;

            for(int j=i;j<n;j++){

                if(s[j]==ch){
                    l++;
                    mp[{ch,l}]++;
                }
                else{
                    break;
                }

            }
        }

        int maxi=0;

        for(auto it:mp){
            int fir=it.first.second;
            int las=it.second;

            if(las>=3 && fir>maxi){
                maxi=fir;

            }
        }

       

        return maxi==0?-1:maxi;
        
    }
};