class Solution {
public:

   
    void helper(string ans,int open ,int closed,vector<string>&result,int n){
        if(open==n && closed==n){
            result.push_back(ans);
            return;

        }
        if(open<n){
            helper(ans+'(',open+1,closed,result,n);
        }
        if(open>closed){
            helper(ans+')',open,closed+1,result,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>result;
        int open=0;
        int closed=0;
        string ans="";
        helper(ans,open,closed,result,n);
        return result;
    }
};