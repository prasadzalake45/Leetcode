class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      int n = nums.size();
        int total = 1 << n;
        int sum = 0;

        for (int i = 0; i < total; i++) {
            int xorVal = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    xorVal ^= nums[j];
                }
            }
            sum += xorVal;
        }

        return sum;
        
    }
};