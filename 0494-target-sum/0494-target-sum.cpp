class Solution {
public:
    int helper(vector<int>& nums, int target,int sum,int i,vector<unordered_map<int,int>>&dp) {

       
        // if (i==nums.size() && sum == target) {
        //     return 1;
        // }

        // if(i==nums.size() && sum!=target){
        //     return 0;
        // }

        if(i==nums.size()){
            return sum==target;
        }

        if(dp[i].find(sum)!=dp[i].end()){
            return dp[i][sum];
        }


        int addPlus=helper(nums,target,sum+nums[i],i+1,dp);

        int addMinus=helper(nums,target,sum-nums[i],i+1,dp);

        return dp[i][sum]=addPlus+addMinus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        // you have to build the expression out of nums by addding each integer
        // one of the symbol + or -
        // before eacg integer in nums and concentatnate

        // at evety integer we have two option either + or -
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        return helper(nums, target,0, 0,dp);
    }
};