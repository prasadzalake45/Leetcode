class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

      int n=intervals.size();

      sort(intervals.begin(),intervals.end());
      vector<vector<int>>answer;

      int first1=intervals[0][0];
      int first2=intervals[0][1];


      for(int i=1;i<n;i++){
        int second1=intervals[i][0];
        int second2=intervals[i][1];

        if(first2>=second1){
          first1=min(first1,second1);
          first2=max(first2,second2);
        }
        else{
          answer.push_back({first1,first2});
          first1=intervals[i][0];
          first2=intervals[i][1];


        }
      }
                answer.push_back({first1,first2});

      




      return answer;
        
    }
};