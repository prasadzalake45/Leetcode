class Solution {
public:

    bool isPossible(vector<int>&piles,int mid,int h){
        long long total=0;


        for(int i=0;i<piles.size();i++){
            total+=ceil((double)piles[i]/mid);
        }

        if(total>h){
            return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;

        long long high=*max_element(piles.begin(),piles.end());

        long long result=high;

        while(low<=high){

            long long mid=(low+high)/2;

            if(isPossible(piles,mid,h)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }

        return result;
        
    }
};