    class Solution {
    public:

    int maxi  = 1; 
    int startIdx=0;
        void checkValidPalidrone(string s, int start,int end) {

           

            if (start < 0 || end>= s.size() || s[start] != s[end]) {
                return;
            }

            int curSize=end-start+1;

            if(curSize>maxi){
                maxi=curSize;
                startIdx=start;

            }
            
            checkValidPalidrone(s,start-1,end+1);
        }
        string longestPalindrome(string s) {

            int n = s.size();


            if(n==1){
                return s;
            }


            for (int i = 0; i < n; i++) {

                checkValidPalidrone(s, i-1,i+1);// odd
                checkValidPalidrone(s,i,i+1);//even
            }


            return s.substr(startIdx,maxi);
        }
    };