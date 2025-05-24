class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>vec;
        for(int i=0;i<words.size();i++){
            string ans=words[i];
            if(ans.find(x)!=string::npos){
                vec.push_back(i);
            }
        }

        return vec;
        
    }
};