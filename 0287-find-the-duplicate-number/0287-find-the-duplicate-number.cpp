class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size();

      int slow=0;
      int fast=1;
      int ans;

      while(fast<n){

        if(nums[slow]==nums[fast]){
          ans=nums[slow];
          break;

        }
        else{
          slow++;
          fast++;
        }
       
      }

      return ans;
        
    }
};