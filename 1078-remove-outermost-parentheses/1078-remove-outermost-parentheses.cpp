class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char>st;

        string ans="";

        for(char ch:s){
            if(st.empty() && ch=='('){
                st.push(ch);
            }
            else if(!st.empty() && ch=='('){
                st.push(ch);
                ans+=ch;
            }
            else if(ch==')'){
                if(st.size()==1){
                    st.pop();

                }
                else{
                    ans+=ch;
                    st.pop();
                }
                
            }
        }

        return ans;
    }
};