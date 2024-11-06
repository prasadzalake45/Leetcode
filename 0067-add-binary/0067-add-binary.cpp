class Solution {
public:
    string addBinary(string a, string b) {
        int maxLength=max(a.length(),b.length());


        while(a.length()<maxLength){
            a='0'+a;
        }

        while(b.length()<maxLength){
            b='0'+b;
        }


        string res="";
        int carry=0;

        for(int i=maxLength-1;i>=0;i--){

            int sum=(a[i]-'0')+(b[i]-'0')+carry;

            res=char((sum%2)+'0')+res;
            carry=sum/2;
        }


        if(carry){
            res='1'+res;
        }


        return res;




        
    }
};