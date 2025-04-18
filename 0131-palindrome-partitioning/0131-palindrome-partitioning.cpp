class Solution {
public:

     bool palindrone(string s,int str,int e){

       while(str<=e){
           if(s[str++]!=s[e--]){
               return false;


           }
           
     }
     return true;
   
   }
    void helper(int start,string s,vector<string>&ans,vector<vector<string>>&result){
        if(start==s.size()){
            result.push_back(ans);
        }

        for(int i=start;i<s.size();i++){
            if(palindrone(s,start,i)){
                ans.push_back(s.substr(start,i-start+1));
                helper(i+1,s,ans,result);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<string>ans;
        vector<vector<string>>result;
        int start=0;
        helper(start,s,ans,result);
        return result;
        
    }
};