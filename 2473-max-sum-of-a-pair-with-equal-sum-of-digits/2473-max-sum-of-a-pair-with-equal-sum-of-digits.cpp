class Solution {
public:

    int getDigitSum(int a){

        int digit=0;

        while(a>0){
            digit+=a%10;
            a=a/10;
        }
        return digit;
    }
    int maximumSum(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,int>mp;
        int result=-1;
        for(int i=0;i<n;i++){

            if(mp.count(getDigitSum(nums[i]))){


    
                result=max(result,nums[i]+mp[getDigitSum(nums[i])]);

                mp[getDigitSum(nums[i])]=max(nums[i],mp[getDigitSum(nums[i])]);

            }
            else{
                mp[getDigitSum(nums[i])]=nums[i];
            }

        }

        return result;
        
    }
};