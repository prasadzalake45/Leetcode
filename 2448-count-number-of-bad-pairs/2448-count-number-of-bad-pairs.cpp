class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();

        

        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }

        long long result=0;

       
        unordered_map<int,int>mp;
        mp[nums[0]]=1;

        for(int j=1;j<n;j++){

            int countNJ=mp[nums[j]];

            int totalnumberbeforej=j;

            int badPair=totalnumberbeforej-countNJ;

            result+=badPair;

            mp[nums[j]]++;



        }
         return result;
    }
};