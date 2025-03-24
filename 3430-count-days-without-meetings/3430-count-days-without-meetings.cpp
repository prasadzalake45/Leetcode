class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());


        int ans=0;
        int ending=0;

        for(int i=0;i<n;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];

            if(start>ending+1){
                ans+=start-ending-1;
            }

            ending=max(ending,end);

           

        }

        ans+=days-ending;

        return ans;
        
    }
};