class Solution {
public:
    bool helper(string s1, string s2, string s3, int i, int j,vector<vector<int>>&dp) {

        // base condition

        // take s1

        if (i >= s1.size() && j >= s2.size()) {
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       

        bool takeS1 = false;

        if (i<s1.size() && s1[i] == s3[i + j]) {
            takeS1 = helper(s1, s2, s3, i + 1, j,dp);
        }
        bool takeS2 = false;

        if (j<s2.size() && s2[j] == s3[i + j]) {
            takeS2 = helper(s1, s2, s3, i, j + 1,dp);
        }

        return dp[i][j]=takeS1 || takeS2;
    }
    bool isInterleave(string s1, string s2, string s3) {


        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }

        int n=s3.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(s1, s2, s3, 0, 0,dp);
    }
};