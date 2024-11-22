class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {


        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<string,int>mp;

        for(vector<int>&curRow:matrix){

            string str="";
            int firstval=curRow[0];

            for(int col=0;col<n;col++)
            {

                str+=(curRow[col]==firstval)?"S":"B";

            }

            mp[str]++;


             
        }
        int maxi=0;

        for(auto it:mp){

        maxi=max(maxi,it.second);
        }

        return maxi;
        
    }
};