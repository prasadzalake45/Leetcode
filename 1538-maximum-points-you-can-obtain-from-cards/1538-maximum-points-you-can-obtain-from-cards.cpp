class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

      
        int lsum=0;
        int maxi=0;
        int n=cardPoints.size();
          

       for(int i=0;i<k;i++){
          lsum+=cardPoints[i];

       }

       maxi=lsum;





       int right=n-1;

       int rsum=0;

       for(int i=k-1;i>=0;i--){
        lsum=lsum-cardPoints[i];
        rsum+=cardPoints[right];
        right--;
        maxi=max(maxi,rsum+lsum);

        
       }

       return maxi;
        
    }
};