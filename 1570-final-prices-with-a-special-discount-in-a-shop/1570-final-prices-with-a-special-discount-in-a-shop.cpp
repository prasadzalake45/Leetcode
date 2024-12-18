class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n=prices.size();

        vector<int>ans;

        for(int i=0;i<n-1;i++){
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(prices[j] <= prices[i]){
                    flag=1;
                    ans.push_back(prices[i]-prices[j]);
                    break;
                }
                
            }
            if(flag==0){
                ans.push_back(prices[i]);
            }
        }

        ans.push_back(prices[n-1]);

        return ans;
        
    }
};