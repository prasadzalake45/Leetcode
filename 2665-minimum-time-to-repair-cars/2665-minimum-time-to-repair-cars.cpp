class Solution {
public:
   
    bool isPossible(vector<int>&ranks,int cars,long long  mid){

        long long cnt=0;
        for(auto r:ranks){
            cnt+=sqrt(mid/r);
           


        }

        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long  maxi=*max_element(ranks.begin(),ranks.end());
        int n=ranks.size();

        long long l=1;
        long long r=1LL*cars*cars*maxi;
        long long  result=r;
        
        while(l<=r){
            long long   mid=l+(r-l)/2;

            if(isPossible(ranks,cars,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return result;
    }
};