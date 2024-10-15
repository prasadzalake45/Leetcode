class Solution {
public:
    long long minimumSteps(string s) {
        long long  ones=0;
        long long  cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt+=ones;
            }
            else if(s[i]=='1'){
                ones++;
            }
        }

        return cnt;
    }
};