class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxi = 0;

        for (int i = 1; i < n; i++) {
            int m = arrays[i].size();

            maxi = max(maxi, abs(arrays[i].back() - minVal));
            maxi = max(maxi, abs(maxVal - arrays[i][0]));

            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxi;
    }
};
