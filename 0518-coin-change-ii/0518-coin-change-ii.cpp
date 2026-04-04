class Solution {
public:
    int helper(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){

        if(i>=coins.size()){
            return 0;
        }

        if(amount==0){
            return 1;
        }

        if(amount<0){
            return 0;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int include=helper(amount-coins[i],coins,i,dp);

        int exlcude=helper(amount,coins,i+1,dp);

        return dp[i][amount]=(include+exlcude);


    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        return helper(amount,coins,0,dp);

    }
};