class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>s;

        int n=nums.size();


        int i=0;
        int j=0;

        long long maxi=0;
        long long sum=0;

        while(j<n){
          


            if(s.count(nums[j])==0){
                s.insert(nums[j]);
                sum+=nums[j];
                j++;

            }
            else{
                s.erase(nums[i]);
                sum-=nums[i];
            
                i++;
            }

            if(j-i==k){
                maxi=max(maxi,sum);
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
        }

        return maxi;


    }
};