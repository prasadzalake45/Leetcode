class Solution {
public:
    string smallestNumber(string pattern) {

        int cnt=1;
        string result="";

        stack<int>st;

        for(int i=0;i<pattern.size();i++){
            
            if(pattern[i]=='I'){
                st.push(cnt++);


              
                while(!st.empty()){
                    result+=to_string(st.top());
                    st.pop();
                }
            }
            else{
                
                
                st.push(cnt++);
            }
          
               
        }

        st.push(cnt);
        while(!st.empty()){
            result+=to_string(st.top());
            st.pop();
        }


        return result;


    
        
    }
};