class Solution {
public:
    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // matched

        if (text1[i] == text2[j]) {
            return dp[i][j]=1 + lcs(text1, text2, i - 1, j - 1, dp);
        }
        // not matched
        return dp[i][j] = max(lcs(text1, text2, i - 1, j, dp),
                              lcs(text1, text2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.size();
        int n2 = text2.size();

        int i = n1 - 1;
        int j = n2 - 1;

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return lcs(text1, text2, i, j, dp);
    }
};