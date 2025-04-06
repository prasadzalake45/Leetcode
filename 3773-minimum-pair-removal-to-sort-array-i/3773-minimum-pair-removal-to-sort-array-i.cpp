class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
      

      

        int cnt=0;


        while(!is_sorted(nums.begin(),nums.end())){
            int n=nums.size();

           int index=-1;
            int mini=INT_MAX;

        for(int i=0;i<n-1;i++){
            int sum=nums[i]+nums[i+1];

           
            if(sum<mini){
                mini=sum;
               
                index=i;
                
            }
        }
            nums[index]=mini;
            nums.erase(nums.begin()+index+1);
           
            
            cnt++;
            

            


            
        }

        return cnt;
        
    }
};