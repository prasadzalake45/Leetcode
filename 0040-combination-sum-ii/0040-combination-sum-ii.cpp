class Solution {
public:

   void helper(int start,vector<int>&candidates,int target,vector<int>&ds,vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i!=start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
              ds.push_back(candidates[i]);
              helper(i+1,candidates,target-candidates[i],ds,ans);
              ds.pop_back();

            }
         


        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int>ds;
        vector<vector<int>>ans;

        int start=0;

        sort(candidates.begin(),candidates.end());
        helper(start,candidates,target,ds,ans);
        return ans;
    }
};