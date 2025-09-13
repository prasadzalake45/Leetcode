class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      intervals.push_back(newInterval);
      sort(intervals.begin(),intervals.end());

      vector<vector<int>>answer;
      vector<int>cur=intervals[0];


      for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=cur[1]){
          cur[1]=max(intervals[i][1],cur[1]);
        }
        else{
          answer.push_back(cur);
          cur=intervals[i];
        
        }
      }

      answer.push_back(cur);

      return answer;
        
    }
};