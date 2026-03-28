class Solution {
public:

    int helper(vector<int>&nums,vector<int>&dp,int n){

        if(n<0){
            return 0;
        }

        if(n==0){
            return nums[0];
        }

       if(dp[n]!=-1){
        return dp[n];
       }
        int take=nums[n]+helper(nums,dp,n-2);
        int notTake=helper(nums,dp,n-1);
         
        dp[n]=max(take,notTake);
        return max(take,notTake);
       
        
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,dp,n-1);
       
        
    }
};