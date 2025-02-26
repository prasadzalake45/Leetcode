class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        int maxSum=0;

        int minSum=0;

        int absolute=0;

        for(int i=0;i<n;i++){

            maxSum=max(maxSum+nums[i],nums[i]);

            minSum=min(minSum+nums[i],nums[i]);


            absolute=max(absolute,max(maxSum,abs(minSum)));

        }

        return absolute;
    }
};