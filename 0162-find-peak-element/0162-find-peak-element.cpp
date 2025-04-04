class Solution {
public:
    int findPeakElement(vector<int>& nums) {

    int n=nums.size();

    for(int i=1;i<n-1;i++){
        if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
            return i;
        }
    }

    if(n==1){
        return 0;
    }

    vector<int>ans;
ans.insert(ans.end(), nums.begin(), nums.end());

    sort(nums.begin(),nums.end());
    if(nums==ans){
        return n-1;
    }

        
    return 0;
    }
};