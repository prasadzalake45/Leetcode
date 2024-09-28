class Solution {
public:
    string decodeString(string s) {

        stack<int>number;
        stack<string>chars;
        string curString="";
        int curNumber=0;

        for(char c:s){
            if(isdigit(c)){
                curNumber = curNumber * 10 + (c - '0');;

            }
            else if(c=='['){
                number.push(curNumber);
                chars.push(curString);
                curNumber=0;
                curString="";
            }
            else if(c==']'){
                int times=number.top();
                number.pop();
                string prevString=chars.top();
                chars.pop();

                string temp=curString;
                for(int i=1;i<times;i++){
                    curString+=temp;
                }

                curString=prevString+curString;



            }
            else{
                curString+=c;
            }
        }

        return curString;
        
    }
};