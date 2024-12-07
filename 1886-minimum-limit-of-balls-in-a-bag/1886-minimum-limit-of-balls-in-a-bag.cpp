class Solution {
public:

    bool canWeDo(vector<int>& nums, int prn, int maxOperations) {
        long long cnt = 0;
        for (int balls : nums) {
            if (balls > prn) {
                cnt += (balls - 1) / prn;
            }
        }
        return  cnt <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int n=nums.size();

        long long low=1;
        long long high=*max_element(nums.begin(),nums.end());
        long result=high;

        while(low<=high){
            long long mid=(low+high)/2;

            if(canWeDo(nums,mid,maxOperations)){
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