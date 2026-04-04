class Solution {
public:
    int helper(vector<int>& nums, int target,int sum,int i) {

       
        if (i==nums.size() && sum == target) {
            return 1;
        }

        if(i==nums.size() && sum!=target){
            return 0;
        }



        int addPlus=helper(nums,target,sum+nums[i],i+1);

        int addMinus=helper(nums,target,sum-nums[i],i+1);

        return addPlus+addMinus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        // you have to build the expression out of nums by addding each integer
        // one of the symbol + or -
        // before eacg integer in nums and concentatnate

        // at evety integer we have two option either + or -

        return helper(nums, target,0, 0);
    }
};