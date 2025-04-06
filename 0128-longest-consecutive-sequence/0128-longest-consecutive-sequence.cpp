class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());

  
        int n=nums.size();

        if(n==0){
            return 0;

        }
        int longest=1;
        int last_smaller=INT_MAX;

        int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]-1==last_smaller){
                cnt=cnt+1;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
                cnt=1;
                last_smaller=nums[i];
            }

            longest=max(longest,cnt);
        }
        return longest;
 

        
    }
};