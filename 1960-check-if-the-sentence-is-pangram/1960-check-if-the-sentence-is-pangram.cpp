class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>s;

        for(char c:sentence){
            s.insert(c);
        }

        for(char ch='a';ch<='z';ch++){
            if(!s.count(ch)){
                return false;
            }
        }

        return true;
        
    }
};