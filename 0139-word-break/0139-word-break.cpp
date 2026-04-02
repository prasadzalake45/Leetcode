class Solution {
public:
   
    bool helper(string s,int i,unordered_set<string>dict,vector<int>&dp){

        if(i==s.size()){
            return true;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        for(auto word:dict){
            string substring=s.substr(i,word.size());

            if(substring==word){
                if(helper(s,i+word.size(),dict,dp)==true){
                    return dp[i]=1;
                }
            }
        }

        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string>dict;

        for(auto word:wordDict){
            dict.insert(word);
        }
        int n=s.size();       
        vector<int>dp(n+1,-1);
        return helper(s,0,dict,dp); 
    }
};