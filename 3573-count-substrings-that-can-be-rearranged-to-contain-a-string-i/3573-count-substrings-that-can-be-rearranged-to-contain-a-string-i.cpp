class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long count = 0;
        unordered_map<char, int> targetFreq, currentFreq;

        // Build frequency map for word2
        for (char ch : word2) {
            targetFreq[ch]++;
        }

        int requiredChars = targetFreq.size(); // Unique characters needed
        int formedChars = 0; // Unique characters in current window that meet frequency

        int left = 0; // Left pointer for the sliding window

        // Expand the window with right pointer
        for (int right = 0; right < word1.size(); right++) {
            char currentChar = word1[right];
            currentFreq[currentChar]++;

            // Check if current character's frequency matches the target
            if (targetFreq.count(currentChar) && currentFreq[currentChar] == targetFreq[currentChar]) {
                formedChars++;
            }

            // While we have a valid window, count valid substrings
            while (formedChars == requiredChars) {
                count += (word1.size() - right); // Count all valid substrings from left to right

                // Remove the leftmost character from the window
                char leftChar = word1[left];
                currentFreq[leftChar]--;

                // Update formedChars if necessary
                if (targetFreq.count(leftChar) && currentFreq[leftChar] < targetFreq[leftChar]) {
                    formedChars--;
                }

                left++; // Move left pointer forward
            }
        }

        return count; // Return the total count of valid substrings
    }
};
