class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeGaps;

        freeGaps.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); ++i) {
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        freeGaps.push_back(eventTime - endTime.back());

        
        int maxFreeDuration = 0, currentSum = 0;

        for (int i = 0; i < freeGaps.size(); ++i) {
            currentSum += freeGaps[i];

            if (i >= k + 1) {
                currentSum -= freeGaps[i - (k + 1)];
            }

            maxFreeDuration = max(maxFreeDuration, currentSum);
        }

        return maxFreeDuration;
    }
};