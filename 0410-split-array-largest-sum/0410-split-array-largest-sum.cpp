class Solution {
public:

    int isPossible(vector<int>&nums,int ans,int k){


      int n=nums.size();

      int student=1;

      int sum=0;


      for(int i=0;i<n;i++){

     if(sum+nums[i]<=ans){
      sum+=nums[i];
     }
     else{
      sum=nums[i];
      student++;
     }
      

      }

       


      return student;
    }
    int splitArray(vector<int>& nums, int k) {

      int n=nums.size();

      if(k>n){
        return -1;
      }

      int low=*max_element(nums.begin(),nums.end());
      int high=accumulate(nums.begin(),nums.end(),0);

      int ans=-1;


      while(low<=high){
        int mid=(low+high)/2;

        if(isPossible(nums,mid,k)>k){
          
          low=mid+1;

        }
        else{
          ans=mid;
         
          high=mid-1;
        }
      }

      

      return ans;
        
    }
};