class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        
        int m=mat.size();
        int n=mat[0].size();

        unordered_map<int,pair<int,int>>posMap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                posMap[mat[i][j]]={i,j};
            }
        }

        vector<int>rowCnt(m,0);
        vector<int>colcnt(n,0);
        for(int i=0;i<arr.size();i++){
            auto[row,col]=posMap[arr[i]];

            rowCnt[row]++;
            colcnt[col]++;
            if(rowCnt[row]==n || colcnt[col]==m){
                return i;
            }
        }

        return -1;


       

        
        
    }
};