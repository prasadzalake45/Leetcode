class Solution {
public:

    int helper(string word1,string word2,int i,int j,vector<vector<int>>&dp){
          
          if(i==word1.size()){
             return word2.size()-j;
          }

          if(j==word2.size()){
            return word1.size()-i;
          }
           
        if(dp[i][j]!=-1){
            return dp[i][j];
        }


          if(word1[i]==word2[j]){
            return dp[i][j]=helper(word1,word2,i+1,j+1,dp);
          }

          return dp[i][j]=1+min({helper(word1,word2,i+1,j,dp),helper(word1,word2,i,j+1,dp),helper(word1,word2,i+1,j+1,dp)});


    }
    int minDistance(string word1, string word2) {


         // case 1 character matching
         // doing nothing got to next charactet for both

         // case 2 character Not matching 
            //i) insert
            // ii) delete
            // iii) replace
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(word1,word2,0,0,dp);
        
    }
};