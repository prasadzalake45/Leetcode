class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        stack<string>st;
        string word;

        while(ss>>word){
            st.push(word);
        }


        string answer="";

        while(!st.empty()){
            answer+=st.top();
            st.pop();

            if(!st.empty()){
                answer+=" ";
            }
        }



        return answer;
    }
};