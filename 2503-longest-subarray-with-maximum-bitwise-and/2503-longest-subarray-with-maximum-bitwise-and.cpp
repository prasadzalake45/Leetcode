class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }


        int cnt=0;
        int maxl=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                cnt++;

                maxl=max(maxl,cnt);

            
            }
            else{
                cnt=0;
            }
        }

       

        return maxl;
        
    }
};