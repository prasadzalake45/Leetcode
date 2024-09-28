class Solution {
public:

    
    long long  helper(vector<int>&piles,long r){
        
        long long  totalhr=0;
        for(int i=0;i<piles.size();i++){
            totalhr+=ceil((double (piles[i])/double (r)));
        }
        

        return totalhr;


    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int cur=INT_MAX;

        while(low<=high){
            long mid=(low+high)/2;

            long long  ans=helper(piles,mid);

            if(ans<=h){
                cur=mid;
                high=mid-1;

                
            }
            else{
                low=mid+1;
            }
        }
        return cur;

        



        
    }
};