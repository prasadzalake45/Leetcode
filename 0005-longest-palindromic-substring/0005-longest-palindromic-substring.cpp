class Solution {
public:

    bool checkPalindrone(string& s,int start,int end,vector<vector<int>>& dp){
        if(start>=end){
            return 1;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        if(s[start]==s[end]){
            return dp[start][end]=checkPalindrone(s,start+1,end-1,dp);
        }

        return dp[start][end]=0;

        

    }
    string longestPalindrome(string s) {

        int n=s.size();
        int maxi=1;
        int startIdx=0;


vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrone(s,i,j,dp)==true){
                    if(j-i+1>maxi){
                       maxi=j-i+1;
                       startIdx=i;
                    }
                }
            }
        }
        

        return s.substr(startIdx,maxi);
    }
};