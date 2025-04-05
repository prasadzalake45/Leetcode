class Solution {
public:

    long long  helper(vector<int>&piles,int mid){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=ceil(double(piles[i])/mid);
           
            
        }
        return sum;

    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n=piles.size();

        int mini=1;
        int maxi=*max_element(piles.begin(),piles.end());
        long ans=maxi;
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            if(helper(piles,mid)<=h){
                ans=mid;
                maxi=mid-1;

            }
            else{
                mini=mid+1;
            }
        }
        return ans;


        
    }
};