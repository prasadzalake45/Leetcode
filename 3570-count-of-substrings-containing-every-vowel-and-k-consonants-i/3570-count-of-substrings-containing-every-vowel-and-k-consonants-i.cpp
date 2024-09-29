class Solution {
public:
    bool isVowel(char ch) {

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countOfSubstrings(string word, int k) {
        int n = word.size();
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int result = 0;

        // Sliding window
        unordered_map<char, int> vowelCount;
        int consCount = 0, left = 0;

        for (int right = 0; right < n; right++) {
            if (isVowel(word[right])) {
                vowelCount[word[right]]++;  // Track vowels in the window
            } else {
                consCount++;  // Count consonants
            }

            // Shrink window from the left if there are too many consonants
            while (consCount > k) {
                if (isVowel(word[left])) {
                    vowelCount[word[left]]--;  // Reduce vowel count for left char
                    if (vowelCount[word[left]] == 0) {
                        vowelCount.erase(word[left]);  // Remove from map if no occurrences
                    }
                } else {
                    consCount--;  // Reduce consonant count
                }
                left++;  // Move window forward
            }

            // If we have all vowels and exactly k consonants, count the window
            if (vowelCount.size() == 5 && consCount == k) {
                result++;
            }
        }

        return result;
    }
};

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> s;
            int consCnt = 0;

            for (int j = i; j < n; j++) {
                if (isVowel(word[j])) {
                    s.insert(word[j]);
                } else {
                    consCnt++;
                }

                if (s.size() == 5 && consCnt == k) {
                    result++;
                }

                if (consCnt > k) {
                    break;
                }
            }
        }

        return result;
    }
};