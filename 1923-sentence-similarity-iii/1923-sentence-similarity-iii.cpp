class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1;
        vector<string> v2;

        // Ensure v1 is the longer sentence, v2 is the shorter one
        if (sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }

        // Splitting sentence1 (the longer one) into words
        stringstream ss1(sentence1);
        string word;
        while (ss1 >> word) {
            v1.push_back(word);
        }

        // Splitting sentence2 (the shorter one) into words
        stringstream ss2(sentence2);
        while (ss2 >> word) {
            v2.push_back(word);
        }

        int n = v1.size();
        int m = v2.size();
        
        // Check if v2 matches a prefix of v1
        int prefixMatch = 0;
        while (prefixMatch < m && v1[prefixMatch] == v2[prefixMatch]) {
            prefixMatch++;
        }

        // Check if v2 matches a suffix of v1
        int suffixMatch = 0;
        while (suffixMatch < m && v1[n - 1 - suffixMatch] == v2[m - 1 - suffixMatch]) {
            suffixMatch++;
        }

        // If the total matched prefix and suffix covers all of v2, then return true
        return prefixMatch + suffixMatch >= m;
    }
};
