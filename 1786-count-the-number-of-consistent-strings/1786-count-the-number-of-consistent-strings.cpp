class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        

        unordered_set<char>s;
        for(char ch:allowed){
            s.insert(ch);
        }
        int cnt=0;

        for(int i=0;i<words.size();i++){

            int j=0;

            while(j<words[i].size() && s.find(words[i][j])!=s.end()){
                j++;
                if(j==words[i].size()){
                    cnt++;
                }
            }
            

        }
        return cnt;
    }
};