class Solution {
public:


    int helper(vector<int>&prices,int state,int i,vector<vector<int>>&dp){

        if(i>=prices.size()){
            return 0;
        }

        if(dp[i][state]!=-1){
            return dp[i][state];
        }

        if(state==0){
            // buying
            int buying=-prices[i]+helper(prices,1,i+1,dp);
 
            // not buying
            int skipBuying=helper(prices,0,i+1,dp);

            return dp[i][state]=max(buying,skipBuying);

        }
        else if(state==1){
            // sell it or not
 
            // selling
            int selling=prices[i]+helper(prices,2,i+1,dp);


            // not selling

            int notSelling=helper(prices,1,i+1,dp);

        
            return dp[i][state]=max(selling,notSelling);

        }
        else if(state==2){
            // go to i+2 simply

            return helper(prices,0,i+1,dp);

        }

        return dp[i][state]=0;

    }
  

    
    int maxProfit(vector<int>& prices) {

        // first i need to Buy the stcok once I buy I only sell and make sure I
        // sell as Max as possible once I sell I cannont take i+1 as it cooling
        // down period now this is what i  am thinking but did not chatch with
        // how the recursive calls are getting made lets me clear with this


        // 3 State ---FREE,HOLD,COOL
        int i = 0;
        int state = 0;
        int n=prices.size();

        vector<vector<int>>dp(n,vector<int>(3,-1));
        return helper(prices,state,i,dp);
    }
};