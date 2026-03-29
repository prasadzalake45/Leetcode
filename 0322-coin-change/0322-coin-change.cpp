class Solution {
public:

    int helper(vector<int>& coins,vector<vector<int>>&dp, int amount,int n){
        if(amount<0){
            return 1e9;
        }
        if(amount==0){
            return 0;
        }

        if(n<0){
            return 1e9;
        }


         if(dp[n][amount]!=-1){
            return dp[n][amount];
         }
        // include the coin

        int include=1+helper(coins,dp,amount-coins[n],n);

        // exclude the coin

        int exclude=helper(coins,dp,amount,n-1);

        return dp[n][amount]=min(include,exclude);


    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); 
        int ans=helper(coins,dp,amount,n-1);

        if(ans>=1e9){
            return -1;
        }
       

        return ans;
        

      
    }
};