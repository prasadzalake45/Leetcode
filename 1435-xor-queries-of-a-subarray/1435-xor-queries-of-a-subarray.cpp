class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n1=arr.size();
        int n=queries.size();
        vector<int>vec;


        for(int i=0;i<n;i++){
            int XOR=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                XOR=XOR^arr[j];


            }
            vec.push_back(XOR);
        }

        return vec;

        
        
    }
};