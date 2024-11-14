class Solution {
public:

    bool possible(int x,vector<int>&quantities,int n){

        for(int prod:quantities){
            n-=(prod+x-1)/x;
            if(n<0){
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {

        int maxi=*max_element(quantities.begin(),quantities.end());

        int left=1;
        int right=maxi;
        int res=0;

        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(possible(mid,quantities,n)){
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return res;
        
    }
};