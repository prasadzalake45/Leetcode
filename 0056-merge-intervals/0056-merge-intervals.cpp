class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
      
        vector<vector<int>>vec;
        auto it=intervals[0];

        for(int i=1;i<n;i++){
            if(it[1]>=intervals[i][0]){
                it[1]=max(it[1],intervals[i][1]);
            }
            else{
                vec.push_back(it);
                it=intervals[i];
            }
        }

        vec.push_back(it);

        return vec;


        
    }
};