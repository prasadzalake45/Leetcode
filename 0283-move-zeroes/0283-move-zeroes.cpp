class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();

        vector<int>ans;

        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
                cnt++;
            }
        }

        int size=n-cnt;

        ans.insert(ans.end(),size,0);

        nums=ans;
        
        
        
    }
};