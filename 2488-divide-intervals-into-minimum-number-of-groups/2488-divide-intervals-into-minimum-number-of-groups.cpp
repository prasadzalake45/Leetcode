class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());


        priority_queue<int,vector<int>,greater<int>>minH;


        for(auto it:intervals){
            int start=it[0];
            int end=it[1];

            if(!minH.empty() && minH.top()<start){
                minH.pop();
            }

            minH.push(end);
        }

        return minH.size();
        
    }
};