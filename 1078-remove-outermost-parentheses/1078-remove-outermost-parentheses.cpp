class Solution {
public:
    string removeOuterParentheses(string s) {

        int n=s.size();
        int cnt=0;
        string ans="";

        for(int i=0;i<n;i++){
            if(s[i]=='('){

                if(cnt>0){
                    ans+=s[i];

                }

                cnt++;

            }
            else if(s[i]==')'){

                cnt--;

                if(cnt>0){
                    ans+=s[i];
                }

            }
        }

        return ans;

        
    }
};