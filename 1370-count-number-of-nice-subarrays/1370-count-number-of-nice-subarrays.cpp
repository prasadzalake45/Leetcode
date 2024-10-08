class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        int sum=0;
        int cnt=0;
        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                sum++;
            }

            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }

            mp[sum]++;
        }

        return cnt;
        
    }
};