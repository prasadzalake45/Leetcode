class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns=s.size();
        int nt=t.size();

        if(ns!=nt){
            return false;
        }

        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }


        for(auto it:t){
            if(mp.find(it)!=mp.end()){
                mp[it]--;
                if(mp[it]==0){
                    mp.erase(it);
                }
            }
        }


        return mp.size()==0;
    }
};