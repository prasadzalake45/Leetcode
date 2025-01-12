class Solution {
public:
    bool canBeValid(string s, string locked) {

         int n = s.length();
        
        // If the length is odd, it's impossible to make a valid parentheses string.
        if (n % 2 != 0) return false;
        
        int open = 0, close = 0;
        
        // Left-to-right scan
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                open++;
            } else {
                close++;
            }
            if (close > open) return false;
        }
        
        open = 0;
        close = 0;
        
        // Right-to-left scan
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                close++;
            } else {
                open++;
            }
            if (open > close) return false;
        }
        
        return true;
    }
};