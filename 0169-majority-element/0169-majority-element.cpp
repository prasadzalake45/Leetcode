class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;

        int element;


        for(int i=0;i<nums.size();i++){

            if(cnt==0){
                cnt=1;
                element=nums[i];
            }

            else  if(element==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }

        }

        int c=0;
        for(int i=0;i<nums.size();i++){
            if(element==nums[i]){
                c++;
            }
        }

        if(c>(nums.size()/2)){
            return element;
        }

        return -1;


        
    }
};