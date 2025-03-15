class Solution {
public:

    bool isPossible(vector<int>&nums,int k,int mid){
        int house=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                house++;
                i++;
            }
        }

        return house>=k;

    }
    int minCapability(vector<int>& nums, int k) {

        int n=nums.size();

        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        int result=high;

        while(low<=high){

            int mid=(low+high)/2;


            if(isPossible(nums,k,mid)){
                result=mid;
                high=mid-1;


            }
            else{
                low=mid+1;
            }





        }

        return result;
        
    }
};