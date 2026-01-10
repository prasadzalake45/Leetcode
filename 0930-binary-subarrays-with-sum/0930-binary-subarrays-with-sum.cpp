class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int i=0;
        int j=0;
        int cnt=0;
        long long sum=0;
        int n=nums.size();
        
        if(goal<0){
            return 0;
        }

        

        while(j<n){

            sum+=nums[j];

            while(sum>goal){
                sum-=nums[i];
                i++;
            }

            cnt+=(j-i+1);
            j++;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
         return helper(nums,goal)-helper(nums,goal-1);
         
        
        
    }
};