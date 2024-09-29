class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countOfSubstrings(string word, int k) {

        int n = word.size();

        int left = 0;

        int consCnt = 0;
        int res = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) {

            if (isVowel(word[right])) {
                mp[word[right]]++;
            } else {
                consCnt++;
            }

            while (consCnt > k) {
                if (isVowel(word[left])) {
                    mp[word[left]]--;
                    if (mp[word[left]] == 0) {
                        mp.erase(word[left]);
                    }

                }

                else {
                    consCnt--;
                }
                left++;
            }

            if (mp.size() == 5 && consCnt == k) {
                res++;
            }
        }
        return res++;
    }
};