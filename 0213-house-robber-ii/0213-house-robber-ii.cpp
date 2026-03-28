class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int n) {

        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return nums[0];
        }

        if (dp[n] != -1) {
            return dp[n];
        }
        int take = nums[n] + helper(nums, dp, n - 2);

        int notTake = helper(nums, dp, n - 1);

        return dp[n] = max(take, notTake);
    }

     int range(vector<int>& nums,int start,int end) {
        int size=end-start+1;
        vector<int> dp(size, -1);

        vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
        return helper(sub,dp,size-1);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        int exclude0=range(nums,1,n-1);
        int exlcudeN=range(nums,0,n-2);

        return max(exclude0,exlcudeN);
    }
};