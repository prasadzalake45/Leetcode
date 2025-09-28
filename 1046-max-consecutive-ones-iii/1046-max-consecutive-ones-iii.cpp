class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int zeros = 0;
        int maxi = INT_MIN;

        while (j < n) {

            if (nums[j] == 0) {
                zeros++;

                while (zeros > k) {
                   

                    if (nums[i] == 0) {
                        zeros--;
                    }
                     i++;
                }
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};