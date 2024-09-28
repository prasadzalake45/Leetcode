class Solution {
public:
    long long maximumTotalSum(vector<int>& maxi) {

        sort(maxi.begin(),maxi.end(),[](int a,int b){
            return a>b;
        });

        int nextAvai=maxi[0];

        long long  sum=0;

        for(int i=0;i<maxi.size();i++){

            if(maxi[i]>nextAvai){
                maxi[i]=nextAvai;
            }

            if(maxi[i]<=0){
                return -1;
            }

            sum+=maxi[i];

            nextAvai=maxi[i]-1;
            





        }

        return sum;
        
    }
};