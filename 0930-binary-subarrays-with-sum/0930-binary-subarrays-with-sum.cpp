class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {



        unordered_map<int,int>mp;

        // if(nums[0]!=0){
 mp[0]=1;
        
       
        int sum=0;
        int cnt=0;
        int n=nums.size();

       for(int i=0;i<n;i++){
          sum+=nums[i];
            

         

    
          if(mp.find(sum-goal)!=mp.end()){
            cnt+=mp[sum-goal];
          }

           mp[sum]++;

          
       }


     return cnt;
        
    }
};