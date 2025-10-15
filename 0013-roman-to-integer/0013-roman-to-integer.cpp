class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char, int> mp = {

            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        int i=0;

        while (i<n) {

            if (mp[s[i]] < mp[s[i + 1]]) {
                sum += mp[s[i + 1]] - mp[s[i]];
                i=i+2;
            } else {
                sum += (mp[s[i]]);
                i++;
            }
        }

        return sum; // 1000+
    }
};