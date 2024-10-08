class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(char ch:s){
            if(!st.empty()){
                if(ch==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }

            }
            else{
                st.push(ch);
            }
        }
        int cnt=0;
        while(!st.empty()){
            if(st.top()==']'){
                cnt++;
                st.pop();
             

            }
            else{
              st.pop();
            }
           
        }

        return  (cnt+1)/2;
        
    }
};