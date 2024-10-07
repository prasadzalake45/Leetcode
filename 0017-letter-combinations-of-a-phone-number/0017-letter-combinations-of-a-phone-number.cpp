class Solution {
public:

    unordered_map<char,vector<char>>mp;


    void helper(string curr,string digits,int n,int ind,vector<string>&ans){
        if(ind==n){
            ans.push_back(curr);
            return;
        }


        for(char ch:mp[digits[ind]]){
            helper(curr+ch,digits,n,ind+1,ans);
        }

    }



    
    vector<string> letterCombinations(string digits) {

        
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        int n=digits.size();
        vector<string>ans;


        if(n>0){
            helper("",digits,n,0,ans);
        }
        
        return ans;
    }
};