class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;

         stringstream ss(s1);
         stringstream ss2(s2);
         string word;
         while(ss>>word){
            mp1[word]++;
         }
         string word2;
         while(ss2>>word2){
            mp2[word2]++;
         }

         vector<string>vec;

         for(auto it:mp1){
            if(it.second==1 && mp2[it.first]==0){
                vec.push_back(it.first);
            }
         }
         for(auto it:mp2){
            if(it.second==1 && mp1[it.first]==0){
                vec.push_back(it.first);
            }
         }

         return vec;
    }
};