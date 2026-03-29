class Solution {
public:

    long long helper(string s,vector<int>&dp,int i){
        if(i==s.size()){
            return 1;
        }

        if(s[i]=='0'){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        // goes to first one

        long long ways=helper(s,dp,i+1);


        // goes to second combiningly

        if(i+1<s.size()){

            int two=stoi(s.substr(i,2));

            if(two>=10 && two<=26){
                ways+=helper(s,dp,i+2);
            }

        }


        return dp[i]=ways;


    }
    int numDecodings(string s) {


       int n=s.size();

       vector<int>dp(n+1,-1);

       return helper(s,dp,0);
               
    }
};