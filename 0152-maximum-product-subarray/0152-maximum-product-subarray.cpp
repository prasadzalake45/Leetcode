class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int prod = 1;
        int maxi = INT_MIN;
        int bestSoFar = 1;
        int worstSoFar = 1;

        for (int i = 0; i < n; i++) {

            int tempMax=bestSoFar;
            int tempMin=worstSoFar;
             

            bestSoFar =max({nums[i],tempMax*nums[i],tempMin*nums[i]});

            worstSoFar=min({nums[i],tempMax*nums[i],tempMin*nums[i]});

            maxi=max(maxi,bestSoFar);


        }

        return maxi;
    }
};