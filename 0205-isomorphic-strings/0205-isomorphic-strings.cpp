class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size()!=t.size()){
            return false;
        }

       vector<int>smap(256,0);
       vector<int>tmap(256,0);


       for(int i=0;i<s.size();i++){
        if(smap[s[i]]==0){
            smap[s[i]]=i+1;
        }
        if(tmap[t[i]]==0){
            tmap[t[i]]=i+1;
        }
        if(smap[s[i]]!=tmap[t[i]]){
            return false;
        }
       }


       return true;


      
        
    }
};