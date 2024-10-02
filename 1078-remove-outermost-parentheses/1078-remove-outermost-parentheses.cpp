class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char>st;

        string ans="";

        for(char ch:s){
            if(st.empty() && ch=='('){
                st.push(ch);
            }
            else  if(!st.empty() && ch=='('){
                ans+=ch;
                st.push(ch);
            }
            else if(st.size()==1 && ch==')'){
                st.pop();
            }
            else if(ch=')'){
                ans+=ch;
                st.pop();
            }

        }

        return ans;
        
    }
};