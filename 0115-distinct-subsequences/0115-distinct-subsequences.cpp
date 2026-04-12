class Solution {
public:

   int helper(string s,string t,int i,int j,vector<vector<int>>&dp){
       if(j==t.size()){
        return 1;
      }
      if(i==s.size()){
        return 0;
      }


     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     



     if(s[i]==t[j]){
        return dp[i][j]=helper(s,t,i+1,j+1,dp)+helper(s,t,i+1,j,dp);
     }

     return dp[i][j]=helper(s,t,i+1,j,dp);


   }
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return helper(s,t,0,0,dp);
    }
};