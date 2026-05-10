class Solution {
public:

    int helper(int i,vector<int>&nums,int target,vector<int>&dp){

        if(i==nums.size()-1){
            return 0;
        }

        if(dp[i]!=-2){
            return dp[i];

        }

        int ans=INT_MIN;

        for(int j=i+1;j<nums.size();j++){

            int diff=nums[j]-nums[i];

            if(diff<=target && diff>=-target){

                int next=helper(j,nums,target,dp);


                if(next!=INT_MIN){
                    ans=max(ans,1+next);
                }
            }

        }

        return dp[i]=ans;


    }
    int maximumJumps(vector<int>& nums, int target) {
    int n=nums.size();

        vector<int> dp(n, -2);
        int ans=helper(0,nums,target,dp);

    

         if(ans==INT_MIN){
            return -1;
         }

         return ans;

        
    }
};