class Solution {
public:

    // each i/p has excatlty one solutions
    // not to used same element twice
    //imp
    // 1) consider does it affect when there is array is sorted or not
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;


        

        for(int i=0;i<n;i++){
 
            int ans=target-nums[i];


            if(mp.find(ans)!=mp.end()){
                return {mp[ans],i};
            }
            else{
                mp[nums[i]]=i;

            }
        }

        // if(mp.find(sum-target)!=mp.end()){
        //     return {mp[sum-target],n-1};
        //  }
        
        return {};
        
    }
};