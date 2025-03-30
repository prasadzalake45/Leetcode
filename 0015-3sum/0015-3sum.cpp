class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        set<vector<int>>ans;

        for(int i=0;i<n-2;i++){
            int start=i+1;
            int end=n-1;

            while(start<end){
                if(nums[i]+nums[start]+nums[end]==0){
                    ans.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    
                }
                else if(nums[i]+nums[start]+nums[end]>0){
                    end--;
                }
                else{
                    start++;
                }
            }


        }

        vector<vector<int>>sll;
        for(auto it:ans){
            sll.push_back(it);
        }

        return sll;
        
    }
};