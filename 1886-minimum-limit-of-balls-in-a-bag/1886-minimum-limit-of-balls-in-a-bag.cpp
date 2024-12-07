class Solution {
public:

    bool canWeDo(vector<int>& nums, int mid, int maxOperations) {

        long long total=0;

        for(int i=0;i<nums.size();i++){
            int ops=nums[i]/mid;

            if(nums[i]%mid==0){
                ops-=1;
            }

            total+=ops;

        }

        if(total>maxOperations){
            return false;
        }

        return true;
        
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