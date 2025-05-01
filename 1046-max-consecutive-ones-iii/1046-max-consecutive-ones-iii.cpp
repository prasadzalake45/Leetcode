class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        if(n==k){
            return n;
        }


        int i=0;
        int j=0;

        int maxi=0;

        while(j<n){

            if(nums[j]==0){
                k--;
            }


            if(k<0){
                maxi=max(maxi,j-i);

                if(nums[i]==0){
                    k++;
                }

                i++;
            }

            j++;



        }
        maxi=max(maxi,j-i);



        return maxi;
        
    }
};