class Solution {
public:
    long countSteps(long n, long prefix) {
        long steps = 0;
        long first = prefix, next = prefix + 1;
        // Count numbers between 'prefix' and 'prefix+1'
        while (first <= n) {
            steps += min(n + 1, next) - first;  // Add how many numbers fit in this range
            first *= 10;  // Move to the next level of children
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long current = 1;  // Start from 1
        k--;  // Since we consider current (1st lexicographical number), decrease k by 1
        
        while (k > 0) {
            long steps = countSteps(n, current);
            if (steps <= k) {
                // If the k-th number is not in the current prefix, move to the next prefix
                current++;
                k -= steps;  // Skip all the numbers in the current prefix
            } else {
                // If the k-th number is in the current prefix, move deeper into the tree
                current *= 10;  // Move to the next level of numbers (children of current)
                k--;  // Since we moved down, consume 1 step
            }
        }
        return current;
    }
};