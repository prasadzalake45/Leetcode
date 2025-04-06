class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
      stringstream ss(s);
      string word;

      while(ss>>word){
        st.push(word);
      }

      string ans="";
     while(!st.empty()){
        if(ans.empty()){
            ans+=st.top();
        }
        else{
               ans=ans+" "+st.top();
        }
       
        st.pop();
      }


    return ans;

        
    }
};