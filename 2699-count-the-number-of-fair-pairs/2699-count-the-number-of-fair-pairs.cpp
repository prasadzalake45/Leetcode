class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long  cnt=0;

        for(int i=0;i<n-1;i++){
            

            int idx1=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);

            int x=idx1-1-i;

     idx1=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);



            int y=idx1-1-i;

            cnt+=(y-x);

        }
        return cnt;
    }
};