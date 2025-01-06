class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();

        int prefixcnt=0;
        int prefixopt=0;

        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            ans[i]+=prefixopt;

            if(boxes[i]=='1'){
                prefixcnt++;
            }

            prefixopt+=prefixcnt;

        }
        int suffixcnt=0;
        int suffixops=0;

        for(int i=n-1;i>=0;i--){
            ans[i]+=suffixops;

            if(boxes[i]=='1'){
                suffixcnt++;
            }

            suffixops+=suffixcnt;

        }
        return ans;
        
    }
};