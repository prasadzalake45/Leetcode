class Solution {
public:  
    bool isPossible(vector<int>&weights,int mid,int days){
         
         int da=1;
         int w=0;

         for(int i=0;i<weights.size();i++){
            w+=weights[i];

            if(w>mid){
                da++;
                w=weights[i];
            }

         }
         if(da>days){
            return false;
         }


     return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int n=weights.size();

        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        int result=high;

        while(low<=high){
            int mid=(low+high)/2;

            if(isPossible(weights,mid,days)){
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