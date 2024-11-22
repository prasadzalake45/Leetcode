class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();
        int maxR=0;

        for(auto& curRow:matrix){

            vector<int>inverted(n);

            for(int col=0;col<n;col++){
                inverted[col]=curRow[col]==0?1:0;
            }

            int cnt=0;

            for(auto& row:matrix){
                if(row==curRow || row==inverted){
                    cnt++;
                }
            }

        maxR=max(maxR,cnt);


        }

        return maxR;
        
    }
};