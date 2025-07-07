class Solution {
public:
    void moveZeroes(vector<int>& nums) {


        int n=nums.size();

        //first zero element
        int first=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                first=i;
                break;

                
            }
        }

        if(first==-1){
            return;
        }


        int i=first;
        int j=i+1;

        while(j<n){
            if(nums[j]==0){
                j++;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }

    
    



        
        
        
        
    }
};