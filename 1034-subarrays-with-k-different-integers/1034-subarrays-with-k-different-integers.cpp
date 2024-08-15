class Solution {
public:

    int helper(vector<int>&nums,int k){
        unordered_map<int,int>mp;

        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;

        while(j<n){


            mp[nums[j]]++;
            while(mp.size()>k && i<=j){
                mp[nums[i]]--;

                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=helper(nums,k)-helper(nums,k-1);
        return ans;
        
    }
};