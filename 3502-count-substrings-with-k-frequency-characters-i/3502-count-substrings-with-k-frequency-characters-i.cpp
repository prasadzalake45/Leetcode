class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
    int result = 0;

    for (int left = 0; left < n; ++left) {
        unordered_map<char, int> freqMap;
        
        for (int right = left; right < n; ++right) {
            char currentChar = s[right];
            freqMap[currentChar]++;
            
            bool validSubstring = false;
            for (auto& [ch, freq] : freqMap) {
                if (freq >= k) {
                    validSubstring = true;
                    break;
                }
            }
            
            if (validSubstring) {
                result++;
            }
        }
    }
    return result;
        
    }
};