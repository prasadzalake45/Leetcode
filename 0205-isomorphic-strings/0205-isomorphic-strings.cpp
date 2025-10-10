class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        if(n1!=n2){
            return false;
        }

        vector<int>first(128,0);
        vector<int>second(128,0);

        for(int i=0;i<n1;i++){
            if(first[s[i]]==0){
              first[s[i]]=i+1;
            }
            if(second[t[i]]==0){
                second[t[i]]=i+1;
            }
            
            if(first[s[i]]!=second[t[i]]){
              return false;
            }


        }
        return true;
    }
};