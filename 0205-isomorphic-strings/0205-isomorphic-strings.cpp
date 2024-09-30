class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n1=s.size();
        int n2=t.size();

        if(n1!=n2){
            return false;
        }

        vector<int>vec1(128,0);
        vector<int>vec2(128,0);

        for(int i=0;i<n1;i++){

            if(vec1[s[i]]==0){
                vec1[s[i]]=i+1;
            }            
            if(vec2[t[i]]==0){
               vec2[t[i]]=i+1;
            }
            if(vec1[s[i]]!=vec2[t[i]]){
                return false;
            }

        }

        return true;
        
    }
};