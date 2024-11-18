class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) return vector<int>(n, 0); // If k == 0, return all zeros

        // Step 1: Build the prefix sum array
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + code[i];
        }

        // Step 2: Result array
        vector<int> result(n, 0);

        if (k > 0) {
            // Sum the next k elements for each index
            for (int i = 0; i < n; i++) {
                int start = (i + 1) % n;
                int end = (i + k) % n;

                if (start <= end) {
                    // Case 1: The range doesn't cross the array boundary
                    result[i] = prefix[end + 1] - prefix[start];
                } else {
                    // Case 2: The range wraps around the array
                    result[i] = (prefix[n] - prefix[start]) + prefix[end + 1];
                }
            }
        } else {
            // Sum the previous |k| elements for each index
            int p = -k; // Absolute value of k
            for (int i = 0; i < n; i++) {
                int start = (i - p + n) % n;
                int end = (i - 1 + n) % n;

                if (start <= end) {
                    // Case 1: The range doesn't cross the array boundary
                    result[i] = prefix[end + 1] - prefix[start];
                } else {
                    // Case 2: The range wraps around the array
                    result[i] = (prefix[n] - prefix[start]) + prefix[end + 1];
                }
            }
        }

        return result;
    }
};
