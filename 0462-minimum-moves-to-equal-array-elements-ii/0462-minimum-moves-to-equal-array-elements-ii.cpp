class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;

        int mid=(s+e)/2;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[mid]){
                int sum=nums[mid]-nums[i];
                cnt+=sum;
            }
            else if(nums[i]>nums[mid]){
                int sum=nums[i]-nums[mid];
                cnt+=sum;
            }
        }

        return cnt;
    }
};