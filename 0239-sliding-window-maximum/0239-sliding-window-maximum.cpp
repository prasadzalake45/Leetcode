class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        vector<int> answer;

        deque<int>dq;

        while (j < n) {
             while (!dq.empty() && dq.back() < nums[j]) {
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
            if (j - i+1 < k) {
               

                j++;

            }

            else if (j - i+1  == k) {

                answer.push_back(dq.front());

                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }
                i++;
                j++;
                
            }
        }

        return answer;
    }
};