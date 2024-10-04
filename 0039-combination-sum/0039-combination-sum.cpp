class Solution {
public:



     void helper(int ind,int n,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp){

        if(ind==n){
            if(target==0){
                ans.push_back(temp);
                return;
            }

            return;
        }

        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            helper(ind,n,target-candidates[ind],candidates,ans,temp);
            temp.pop_back();

        }

        helper(ind+1,n,target,candidates,ans,temp);
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        

        vector<vector<int>>ans;
        vector<int>temp;
        int ind=0;
        int n=candidates.size();
        helper( ind, n,target,candidates,ans,temp);
        return ans;
    }
};