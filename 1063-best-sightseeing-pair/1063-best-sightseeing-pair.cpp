class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
     
        int n=values.size();

        vector<int>ans(n);

        int maxi=INT_MIN;
        for(int i=0;i<values.size();i++){
            
            int sum=i+values[i];
           
            if(sum>maxi){
                ans[i]=sum;
                maxi=sum;
            }
            else{
                ans[i]=maxi;
            }
           
        }

        int i=0;
        int j=1;
        int moxi=INT_MIN;
        while(j<n){
            int cur=values[j]-j;
            cur+=ans[j-1];

            moxi=max(moxi,cur);
            j++;
        }

        return moxi;


        
        
    }
};