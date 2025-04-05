class Solution {
public:
 

   void helper(vector<int>&nums,vector<int>&res,vector<vector<int>>&ans,int i){
     
      if(i>=nums.size()){
        ans.push_back(res);
        return;
      }

      res.push_back(nums[i]);
      helper(nums,res,ans,i+1);
      res.pop_back();
      helper(nums,res,ans,i+1);

   }

   

    

     
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>res;
        int i=0;
        helper(nums,res,ans,i);
        return ans;
        

    }
};