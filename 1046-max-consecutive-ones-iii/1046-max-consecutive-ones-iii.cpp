class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();
        int i=0;
        int j=0;
        int zeros=0;
        int maxi=0;
        while(j<n){
            if(nums[j]==0){
                zeros++;

            }

            if(zeros<=k){
                j++;
                maxi=max(maxi,j-i);
            }

            else{
                // maxi=max(maxi,j-i);
                if(nums[i]==0){
                    zeros--;
                }
                i++;
                j++;
            }
        }

        return maxi;
    
        
    }
};