class Solution {
public:

    bool checkPalindrone(string& s,int start,int end){
        if(start>=end){
            return true;
        }

        if(s[start]==s[end]){
            return checkPalindrone(s,start+1,end-1);
        }

        return false;

        

    }
    string longestPalindrome(string s) {

        int n=s.size();
        int maxi=1;
        int startIdx=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrone(s,i,j)==true){
                    if(j-i+1>maxi){
                       maxi=j-i+1;
                       startIdx=i;
                    }
                }
            }
        }
        

        return s.substr(startIdx,maxi);
    }
};