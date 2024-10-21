class Solution {
public:


int backtrack(string &s, int start, unordered_set<string> &used) {
    if (start == s.length()) {
        return 0;  // Reached the end of the string
    }

    int maxSplits = 0;
    string current = "";

    // Explore all possible splits starting from 'start' index
    for (int i = start; i < s.length(); ++i) {
        current += s[i];  // Extend the current substring

        // If the current substring is unique
        if (used.find(current) == used.end()) {
            used.insert(current);  // Add to set
            // Recur to explore the remaining part of the string
            maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, used));
            used.erase(current);   // Backtrack (remove the current substring)
        }
    }

    return maxSplits;
}
    int maxUniqueSplit(string s) {

      

        unordered_set<string> used;
    return backtrack(s, 0, used);
        
    }
};