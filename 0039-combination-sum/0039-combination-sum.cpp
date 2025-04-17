class Solution {
public:

    void helper(int start,vector<int>&candidates,int target,vector<int>&ds,vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(candidates[i]<=target){
              ds.push_back(candidates[i]);
              helper(i,candidates,target-candidates[i],ds,ans);
              ds.pop_back();

            }
         


        }



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>ds;
        vector<vector<int>>ans;
        int start=0;
        helper(start,candidates,target,ds,ans);
        return ans;
    }
};