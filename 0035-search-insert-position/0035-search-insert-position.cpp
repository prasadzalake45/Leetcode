class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
       
        int start=0;
        int end=n-1;
        int ans=-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(nums[mid]==target){
                return mid;
                break;
            }
            else if(nums[mid]>target){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        if(ans==-1){
            return n;
        }

        return  ans;    }
};