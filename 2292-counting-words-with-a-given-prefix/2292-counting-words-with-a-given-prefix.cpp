class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string str=words[i];

            if(str.find(pref)!=string::npos && str.find(pref)==0){
                cnt++;
            }
        }

        return cnt;
        
    }
};