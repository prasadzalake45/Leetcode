class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {


        int n=nums.size();

        int maxi=0;
        for(int num:nums){
            maxi|=num;
        }

        int total=1<<n;

        int cnt=0;

        for(int i=0;i<total;i++){

            int curOr=0;

            for(int j=0;j<n;j++){

                if(i&(1<<j)){
                curOr|=nums[j];

                }

            }

            if(curOr==maxi){
                cnt++;

            }
        }

        return cnt;
        
    }
};