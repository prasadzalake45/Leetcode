class Solution {
public:


//    bool isEven(int a){
//     return a%2==0;
//    }


//    bool isOdd(int a){
//     return a%2==1;
//    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sameParity(n, 0); 
        vector<int> prefixSum(n + 1, 0); 

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                sameParity[i] = 1; 
            }
        }

        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + sameParity[i - 1];
        }

        vector<bool> result;

        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1] - 1; 
            int sameParityCount = prefixSum[end + 1] - prefixSum[start];
            result.push_back(sameParityCount == 0);
        }

        return result;
    }
};