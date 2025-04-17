class Solution {
public:

   void helper(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){

    ans.push_back(ds);

    for(int i=index;i<nums.size();i++){
        if(i!=index && nums[i]==nums[i-1]){
            continue;
        }
        ds.push_back(nums[i]);
        helper(i+1,nums,ds,ans);
        ds.pop_back();
    }
   
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>ds;
        vector<vector<int>>ans;
        int index=0;
        sort(nums.begin(),nums.end());

        helper(index,nums,ds,ans);

        return ans;
        
    }
};