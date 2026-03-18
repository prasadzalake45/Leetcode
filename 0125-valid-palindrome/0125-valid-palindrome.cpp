class Solution {
public:
    bool checkAlpha(char ch){
        cout<<"IN LOOP "<<ch<<endl;
        for(char i='a';i<'z';i++){
            if(i==ch){
                return true;
            }
        }

        for(char i='0';i<='9';i++){
            if(i==ch){
                return true;
            }
        }
        
       
        return false;
    }
    bool isPalindrome(string s) {
        //remove non -alphanumeric
        //uppercase-> lowercase
        //make sure bring it as one string and check if it Palindrone
 

        string str="";
        for(int i=0;i<s.size();i++){
        
            char ch=tolower(s[i]);
            cout<<"lower"<<ch<<endl;
            if(checkAlpha(ch)){
                cout<<"IN"<<ch<<endl;
                str.push_back(ch);
            }
        }

        cout<<str<<endl;
        int n=str.size();
        
        int left=0;
        int right=n-1;

        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;

    }
};