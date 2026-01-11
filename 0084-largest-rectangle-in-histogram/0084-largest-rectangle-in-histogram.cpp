    class Solution {
    public:
        vector<int> nsl(vector<int>& heights) {
            vector<int> left;
            stack<pair<int, int>> st;
            int n = heights.size();
            int psudo = -1;
            for (int i = 0; i < n; i++) {
                if (st.empty()) {
                    left.push_back(psudo);
                } else if (!st.empty() && st.top().first < heights[i]) {
                    left.push_back(st.top().second);
                } else {
                    while (!st.empty() && st.top().first >= heights[i]) {
                        st.pop();
                    }
                    if (st.empty()) {
                        left.push_back(psudo);
                    } else {
                        left.push_back(st.top().second);
                    }
                }
                st.push({heights[i], i});
            }
            return left;
        }

        vector<int> nsr(vector<int>& heights) {
            vector<int> right;
            stack<pair<int, int>> st;
            int n = heights.size();
            int psudo = n;
            for (int i = n - 1; i >= 0; i--) {
                if (st.empty()) {
                    right.push_back(psudo);
                } else if (!st.empty() && st.top().first < heights[i]) {
                    right.push_back(st.top().second);
                } else {
                    while (!st.empty() && st.top().first >= heights[i]) {
                        st.pop();
                    }
                    if (st.empty()) {
                        right.push_back(psudo);
                    } else {
                        right.push_back(st.top().second);
                    }
                }
                st.push({heights[i], i});
            }
            reverse(right.begin(), right.end());
            return right;
        }

        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> rig = nsr(heights);
            vector<int> lef = nsl(heights);
            vector<int> width(n,0);
            vector<long long> area(n);

            for (int i = 0; i < n; i++) {
                width[i] = rig[i] - lef[i] -1;
            }

            for (int i = 0; i < n; i++) {
                area[i] = (long long)heights[i] * (long long)width[i];
            }
            
            int maxi = *max_element(area.begin(), area.end());

            return maxi;
        }
    };
