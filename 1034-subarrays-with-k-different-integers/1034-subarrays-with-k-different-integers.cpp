class Solution {
public:

    int helper(vector<int>&nums,int k){
        int n=nums.size();

        int i=0;
        int j=0;

        unordered_map<int,int>mp;

        int cnt=0;

        while(j<n){

            mp[nums[j]]++;


            while(mp.size()>k){
                mp[nums[i]]--;

                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;

            }

            cnt+=j-i+1;
            j++;

        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
        
    }
};