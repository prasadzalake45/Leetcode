class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        int i=0;
     

        while(i<n1/2){
            if(s1[i]!=s2[i] && s1[i]!=s2[i+2]){
                 return false;
            }
            i++;
        }

        int j=n1/2;

        while(j<n1){
         if(s1[j]!=s2[j] && s1[j]!=s2[j-2]){
                 return false;
            }
            j++;
        }


        

        return true;


    }
};