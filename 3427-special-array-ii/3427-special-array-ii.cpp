class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {


        int n=nums.size();

        vector<int>checkParity(n,0);
        int cnt=1;

        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                checkParity[i]=cnt;
                cnt++;

            }
            else{
                checkParity[i]=checkParity[i-1];

            }
        }

        for(int i=0;i<checkParity.size();i++){
            cout<<checkParity[i]<<" ";
        }

        vector<bool>result;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            

            int ans=checkParity[end]-checkParity[start];
            if(ans==0){
                result.push_back(true);
                
            }
            else{
                result.push_back(false);
            }
        }

        return result;

        
    }
};