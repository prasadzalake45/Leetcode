class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>s;

        int n=nums.size();

    
       int i=0;
       int j=0;
       long long maxi=0;
       long long sum=0;

       while(j<n){

        sum+=nums[j];
        s[nums[j]]++;

        if(j-i+1<k){
            j++;
        }

        else if(j-i+1==k){
            if(s.size()==k){
                maxi=max(maxi,sum);
            }
            s[nums[i]]--;
            if (s[nums[i]] == 0) {
                    s.erase(nums[i]); 
                }
            sum-=nums[i];
            i++;
            
            j++;



        }

       
       }
       return maxi;
        
    }
};