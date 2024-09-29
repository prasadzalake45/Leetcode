class Solution {
public:
    char kthCharacter(int k) {

        string word="a";

        while(word.size()<k){
            string newStr="";

            for(char ch:word){
                char next=(ch=='z')?'a':ch+1;
                newStr+=next;
            }

            word+=newStr;
        }

        return word[k-1];
        
    }
};