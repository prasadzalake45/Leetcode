class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();

        int total=1<<n;

        vector<vector<int>>ans;

        for(int i=0;i<total;i++){
            vector<int>res;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    res.push_back(nums[j]);

                }

            }

            ans.push_back(res);
        }
       
         return ans;
        
    }
};