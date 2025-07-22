class Solution {
public:

    int helper(vector<int>&bloomDay,int m,int k,int ans){

      int n=bloomDay.size();
      int flower=0;
      int bong=0;
      for(int i=0;i<n;i++){
        if(bloomDay[i]<=ans){
           flower++;

          if(flower==k){
            bong++;
            flower=0;

          }
          
        }
        else{
          flower=0;
        }
       
      }

      return bong>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {


      int n=bloomDay.size();

      int low=*min_element(bloomDay.begin(),bloomDay.end());
      int high=*max_element(bloomDay.begin(),bloomDay.end());
      int ans=-1;

      while(low<=high){
        int mid=(low+high)/2;

        if(helper(bloomDay,m,k,mid)){

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