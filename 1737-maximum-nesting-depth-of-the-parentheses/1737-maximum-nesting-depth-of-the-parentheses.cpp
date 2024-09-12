class Solution {
public:
    int maxDepth(string s) {


        int cnt=0;

        // stack<char>st;
        int maxi=INT_MIN;

        for(char ch:s){
            if(ch=='('){
                cnt++;
                maxi=max(cnt,maxi);
            }
            else if(ch==')'){
                cnt--;

            }
            
        }

        if(maxi==INT_MIN){
            return 0;
        }

        return maxi;

    
        
    }
};