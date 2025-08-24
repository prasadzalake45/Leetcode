class Solution {
public:
    bool isPalindrome(string s) {
        

        

        // all convert into upper->lower
        // remove all non -alpha 
        //now check that string valindrone or not
        string str="";


        for(char ch:s){
            if(isalnum(ch)){
                str+=tolower(ch);
            }
        }
        cout<<str<<endl;
        int n=str.size();

        if(n==0){
            return true;
        }
    
        
        int left=0;
        int right=n-1;


        while(left<right){
            if(str[left]!=str[right]){
                return false;
            }
            else{
                left++;
                right--;
            }
        }

        return true;
        

    }
};