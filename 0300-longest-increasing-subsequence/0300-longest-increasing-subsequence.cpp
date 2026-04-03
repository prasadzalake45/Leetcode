class Solution {
public:
    int helper(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {

        if (i >= nums.size()) {
            return 0;
        }

        if (dp[prev+1][i] != -1) {
            return dp[prev+1][i];
        }

        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {

            take = 1 + helper(nums, i + 1, i, dp);
        }

        int notTake = helper(nums, i + 1, prev, dp);

        return dp[prev+1][i] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int prevIndex = -1;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return helper(nums, i, prevIndex,dp);
    }
};