class Solution {
public:
    int findLHS(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());

        int i=0;
        int j=1;
        int maxi=0;

        while(j<nums.size()){


            int sum=nums[j]-nums[i];

            if(sum==1){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(sum>1){
                i++;

            }
            else{
                j++;
            }

        }

        return maxi;
        
        
    }
};