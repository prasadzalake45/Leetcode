class Solution {
public:

    void helper(int n,string curr,int o,int c,vector<string>&ans){

        if(o==n && c==n){
            ans.push_back(curr);
            return;
        }

        if(o>c){
            helper(n,curr+')',o,c+1,ans);
        }

        if(o<n){
            helper(n,curr+'(',o+1,c,ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,"",0,0,ans);
        return ans;



        
    }
};