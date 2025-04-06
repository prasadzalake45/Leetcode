class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int i=0;i<n-1;i++){
            int ans=nums[i+1]-nums[i];
            maxi=max(maxi,ans);



        }
        return maxi;
        
    }
};