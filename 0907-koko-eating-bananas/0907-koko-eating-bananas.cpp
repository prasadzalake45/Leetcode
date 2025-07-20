class Solution {
public:

    long long helper(vector<int>&piles,int ans){

      long long sum=0;

      for(int i=0;i<piles.size();i++){

        sum+=ceil((double)piles[i]/ans);



      }

     

      return sum;


    }
    int minEatingSpeed(vector<int>& piles, int h) {

      int n=piles.size();

      int low=1;
      int high=*max_element(piles.begin(),piles.end());


      // for(int i=mini;i<=maxi;i++){
      //   if(helper(piles,i)<=h){
      //     return i;
      //   }
      // }
      // return -1;

      int ans=-1;

      while(low<=high){

        int mid=(low+high)/2;

        if(helper(piles,mid)<=h){
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