class Solution {
public:

    bool helper(vector<int>&nums,int target,int i,vector<vector<int>>&dp){

        if(target==0){
            return 1;
        }

        if(target<0 || nums.size()==i){
            return 0;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }


        int take=helper(nums,target-nums[i],i+1,dp);
        int notTake=helper(nums,target,i+1,dp);


        return dp[i][target]=take||notTake;



    }
        bool canPartition(vector<int>& nums) {


            // 1 2 5

            // 1 4 3 
            int n = nums.size();

            int totalSum = accumulate(nums.begin(), nums.end(), 0);

            if (totalSum % 2 != 0) {
                return false;
            }

            int target = totalSum / 2;
            int i=0;

            vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
            return helper(nums,target,i,dp);

            
            return false;
        }
};