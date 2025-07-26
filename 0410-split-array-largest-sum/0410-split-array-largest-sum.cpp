class Solution {
public:

    bool isPossible(vector<int>&nums,int ans,int k){


      int n=nums.size();

      int student=1;

      int sum=0;


      for(int i=0;i<n;i++){

        sum+=nums[i];

        if(sum>ans){
          student++;
          sum=nums[i];
        }
      

      }


      return student<=k;
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

        if(isPossible(nums,mid,k)){
          ans=mid;
          high=mid-1;

        }
        else{
          low=mid+1;
        }
      }

      

      return ans;
        
    }
};