class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        

        unordered_map<string,int>m1;
        

        stringstream ss1(s1),ss2(s2);
        string word;

        while(ss1>>word){
            m1[word]++;
        }
        while(ss2>>word){
            m1[word]++;
        }
        vector<string>vec;


        for(auto it:m1){
            if(it.second==1){
                vec.push_back(it.first);
            }
        }

        return vec;
    }
};