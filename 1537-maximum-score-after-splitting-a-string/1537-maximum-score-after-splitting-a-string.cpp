class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxScore=0;

        for(int i=1;i<n;i++){
            int left=count(s.begin(),s.begin()+i,'0');
            int right=count(s.begin()+i,s.end(),'1');
            maxScore=max(maxScore,left+right);
        }

        return maxScore;
    }
};