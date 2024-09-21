class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> vec;

        int n = nums.size();

        for (int k = 0; k < n; k++) {

            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            int i = k + 1;
            int j = n - 1;

            while (i < j) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    vec.push_back({nums[k], nums[i], nums[j]});

                    while (i < j && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    while (i < j && nums[j] == nums[j - 1]) {
                        j--;
                    }

                    i++;
                    j--;
                }
                else if(sum>0){
                    j--;
                }
                else{
                    i++;
                }
            }
        }

        return vec;
    }
};