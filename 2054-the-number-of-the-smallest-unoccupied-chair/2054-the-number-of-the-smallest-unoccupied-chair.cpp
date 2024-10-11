#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // Step 1: Create a vector to hold arrival, leave times and index
        vector<array<int, 3>> friends(n);
        for (int i = 0; i < n; ++i) {
            friends[i] = {times[i][0], times[i][1], i}; // {arrival, leave, index}
        }

        // Step 2: Sort by arrival times
        sort(friends.begin(), friends.end());

        // Step 3: Min-heap for available chairs (0, 1, 2, ...)
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // Initially, all chairs are available
        }

        // Min-heap to track when chairs become free
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving;

        // Step 4: Process each friend in order of arrival
        for (const auto& friendInfo : friends) {
            int arrivalTime = friendInfo[0];
            int leaveTime = friendInfo[1];
            int friendIdx = friendInfo[2];

            // Free up chairs of friends who have left by this arrival time
            while (!leaving.empty() && leaving.top().first <= arrivalTime) {
                availableChairs.push(leaving.top().second); // Chair becomes available
                leaving.pop();
            }

            // Assign the smallest available chair to this friend
            int assignedChair = availableChairs.top();
            availableChairs.pop();

            // If this friend is the target friend, return their chair number
            if (friendIdx == targetFriend) {
                return assignedChair;
            }

            // Track when this friend will leave and free their chair
            leaving.push({leaveTime, assignedChair});
        }

        return -1; // This should not be reached
    }
};
