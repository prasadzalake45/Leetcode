// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
        
//         int ans=0;

//         unordered_map<string,bool>mp;

        

//         for(auto x:dictionary)mp[x]=true;
//         if(s.size()==1){

//              if(mp.find(s)!=mp.end())return 0;
//              return 1;
//         }


//         int n=s.size();
//         vector<bool>visi(n,false);

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 string sub=s.substr(i,j);
//                 // cout<<sub<<endl;
//                 if(mp.find(sub)!=mp.end()){
//                     // cout<<sub<<" "<<i <<" "<<i+j<<endl;
                    
//                    if(i+j<=n){
//                      for(int k=i;k<i+j;k++){
//                         visi[k]=true;
//                     }
//                    }
//                 }
//             }
//         }


//         for(int i=0;i<n;i++){
//             if(!visi[i])ans++;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> memo(s.size(), -1);  // Memoization array

        return dfs(s, 0, dict, memo);
    }

private:
    int dfs(const string& s, int index, unordered_set<string>& dict, vector<int>& memo) {
        // Base case: if we reach the end of the string
        if (index == s.size()) {
            return 0;
        }
        
        // Check memoization
        if (memo[index] != -1) {
            return memo[index];
        }
        
        int minExtra = 1 + dfs(s, index + 1, dict, memo);  // Assume the current character is extra

        // Try all possible substrings starting from the current index
        for (int j = index + 1; j <= s.size(); j++) {
            string sub = s.substr(index, j - index);
            if (dict.find(sub) != dict.end()) {  // If the substring is in the dictionary
                minExtra = min(minExtra, dfs(s, j, dict, memo));  // Skip the valid substring
            }
        }
        
        memo[index] = minExtra;  // Store result in memoization array
        return minExtra;
    }
};
