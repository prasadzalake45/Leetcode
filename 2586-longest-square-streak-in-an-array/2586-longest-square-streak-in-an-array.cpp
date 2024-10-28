class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int maxstreak =-1;

        unordered_set<long long >mp(nums.begin(),nums.end());


        for(int num:nums){
            long long cur=num;
            int length=1;


            while(mp.count(cur*cur)){
                cur*=cur;
                length++;

            }

            if(length>1){
                maxstreak=max(maxstreak,length);
            }
        }

        return maxstreak;
        
    }
};