class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minH;
        for(int i=0;i<n;i++){
            minH.push({nums[i],i});
        }
        
        vector<int>vec(n,0);

        long long cnt=0;

        while(!minH.empty()){
            int el=minH.top().first;
            int ind=minH.top().second;
            minH.pop();

            if(vec[ind]==0){
                cnt+=el;
                vec[ind]=1;

                if (ind > 0) vec[ind - 1] = 1;
                if (ind < n - 1) vec[ind + 1] = 1;

            }
        }

        return cnt;










    }
};