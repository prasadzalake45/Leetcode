class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

       if(n==1){
        return 0;
       }
       



        int start=1;
        int end=n-2;

        while(start<=end){

            int mid=(start+end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1]){
                start=mid+1;



            }
            else{
                end=mid-1;

            }
        }

         if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        if(nums[0]<nums[1]){
            return 1;
        }

        return 0;
        
    }
};