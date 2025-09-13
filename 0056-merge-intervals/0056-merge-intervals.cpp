class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

      sort(intervals.begin(),intervals.end());

      vector<int>cur=intervals[0];
      vector<vector<int>>answer;
      for(int i=1;i<intervals.size();i++){
        if(cur[1]>=intervals[i][0]){
          cur[1]=max(cur[1],intervals[i][1]);
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