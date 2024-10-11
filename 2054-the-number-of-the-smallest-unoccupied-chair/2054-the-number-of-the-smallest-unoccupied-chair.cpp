class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<array<int, 3>> friends(n);
        for (int i = 0; i < n; ++i) {
            friends[i] = {times[i][0], times[i][1], i}; 
        }

        sort(friends.begin(), friends.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving;

        for (const auto& friendInfo : friends) {
            int arrivalTime = friendInfo[0];
            int leaveTime = friendInfo[1];
            int friendIdx = friendInfo[2];

            while (!leaving.empty() && leaving.top().first <= arrivalTime) {
                availableChairs.push(leaving.top().second); 
                leaving.pop();
            }

            int assignedChair = availableChairs.top();
            availableChairs.pop();

            if (friendIdx == targetFriend) {
                return assignedChair;
            }

            leaving.push({leaveTime, assignedChair});
        }

        return -1; 
    }
};
