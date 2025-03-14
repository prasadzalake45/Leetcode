class Solution {
public:

   bool helper(vector<int>&candies,long long k,int mid){
    int n=candies.size();

    long long  cnt=0;

    for(int i=0;i<n;i++){
        cnt+=candies[i]/mid;
        
    }

    return cnt>=k;
   }
    int maximumCandies(vector<int>& candies, long long k) {

        int n=candies.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,candies[i]);
        }


        int l=1;
        int r=maxi;
        long long  result=0;

        while(l<=r){
           int mid=(l+r)/2;

           if(helper(candies,k,mid)){
            result=mid;
            l=mid+1;
           }
           else{
            r=mid-1;
           }
        }

        return result;



    }
};