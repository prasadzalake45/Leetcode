class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(char ch : s) {
            if(!st.empty()) {
                
                if((ch == 'B' && st.top() == 'A') || (ch == 'D' && st.top() == 'C')) {
                    st.pop(); 
                } else {
                    st.push(ch); 
                }
            } 
            
            else {
                st.push(ch); 
            }
        }

        return st.size(); 
    }
};
