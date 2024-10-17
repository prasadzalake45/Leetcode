class Solution {
public:
    int maximumSwap(int num) {

        string ans=to_string(num);
        int n=ans.size();

        vector<int>vec(n);
        vec[n-1]=n-1;

        for(int i=n-2;i>=0;i--){

            int rightmaxInd=vec[i+1];
            int rightmaxEle=ans[rightmaxInd];

            if(ans[i]>rightmaxEle){
                vec[i]=i;
            }
            else{
                vec[i]=rightmaxInd;
            }
        }


        for(int i=0;i<n;i++){
            int maxIdx=vec[i];
            int maxElen=ans[maxIdx];

            if(ans[i]<maxElen){
                swap(ans[i],ans[maxIdx]);

                return stoi(ans); 
        }
        }

        return num;
        
    }
};