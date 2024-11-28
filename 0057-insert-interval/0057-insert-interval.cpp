class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        auto it=newInterval;

        int i=0;

        vector<vector<int>>ans;

        while(i<n && intervals[i][1]<it[0]){
            ans.push_back(intervals[i]);
            i++;

        }

        while(i<n && intervals[i][0]<=it[1]){
           it[0]=min(intervals[i][0],it[0]);
           it[1]=max(intervals[i][1],it[1]);
           i++;

        }

        ans.push_back(it);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }


        return ans;
    }
};