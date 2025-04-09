class Solution {
public:
    void findcomb(int index,vector<int>&arr,vector<int>ds,vector<vector<int>>&result){
        result.push_back(ds);

        for(int i=index;i<arr.size();i++){
            if(i!=index && arr[i]==arr[i-1]) continue;

            ds.push_back(arr[i]);
            findcomb(i+1,arr,ds,result);
            ds.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findcomb(0,nums,ds,result);
        return result;

        
    }
};