class Solution {
public:
    char findKthBit(int n, int k) {


        string s1="0";

        for(int i=1;i<n;i++){

            string a=s1;

            s1+='1';


           int ans;

       for (int j = 0; j < a.size(); j++) {
                a[j] = (a[j] == '0') ? '1' : '0';  // Flip bits
        }

        

        reverse(a.begin(),a.end());
        
    

        s1+=a;


        }

        return s1[k-1];
        
    }
};