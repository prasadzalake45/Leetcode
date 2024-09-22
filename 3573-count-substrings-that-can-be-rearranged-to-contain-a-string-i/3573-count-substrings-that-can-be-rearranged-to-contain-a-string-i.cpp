class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;

        for(char ch:word2){
            mp[ch]++;

        }

        int req=mp.size();
        int uni=0;

        int i=0;
        long long  cnt=0;

        for(int j=0;j<word1.size();j++){
            char curr=word1[j];
            mp2[curr]++;

            if(mp.count(curr)  && mp[curr]==mp2[curr]){
                uni++;


            }

            while(uni==req){
                cnt+=(word1.size()-j);

                char cu=word1[i];
                mp2[cu]--;

                if(mp.count(cu)  && mp2[cu]<mp[cu]){
                    uni--;

                }

                i++;


            }


        }

        return cnt;
    }
};