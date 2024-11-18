class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n=code.size();
        

        vector<int>res(n,0);

        if(k==0){
            return res;
        }


        int i=-1,j=-1;

        if(k>0){
            i=1;
            j=k;

        }
        else{
            i=n-abs(k);
            j=n-1;
        }



        int windowSum=0;

        for(int r=i;r<=j;r++){
            windowSum+=code[r];
        }


        for(int p=0;p<n;p++){

            res[p]=windowSum;
            windowSum-=code[i%n];
            i++;
            windowSum+=code[(j+1)%n];
            j++;

        }

        return res;
    }
};