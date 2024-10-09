class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int i=0;
        int j=0;
        int n=nums.size();
        int sum=0;

        int mini=INT_MAX;
        while(j<n){
            sum+=nums[j];

            while(sum>=target && i<=j){
                mini=min(mini,j-i+1);
                sum-=nums[i];
                i++;

            }

            j++;

        }

        if(mini==INT_MAX){
            return 0;
        }

        return mini;
    }
};