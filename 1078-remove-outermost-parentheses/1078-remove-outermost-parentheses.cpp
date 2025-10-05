class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();

        string str="";
        stack<char>st;

        
         for(char ch:s){

            if(ch=='('){

                if(st.empty()){
                    st.push(ch);
                }

                else{
                    st.push(ch);
                    str+=ch;
                }

        

            }
            else{

                st.pop();

                if(!st.empty()){
                    str+=ch;
                }

            }
         }

         return str;


    }
};