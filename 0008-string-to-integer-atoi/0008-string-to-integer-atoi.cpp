class Solution {
public:
    int myAtoi(string s) {

        // leading whiteSpace REMOVE  (Done)
        // leading ZEROS REMOVE
        // leading -ve sign consider as -VE
        // leadind with word Consider 0
        // leading with zeros after not digit consider 0
        // leading minus only should be consider

        int n = s.size();
        int i = 0;
        int sign = 1;
        long long result = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {

            if (s[i] == '+') {
                i++;
            } else {
                sign = -1;
                i++;
            }
        }

        while (i < n && isdigit(s[i])) {
            result = (result * 10) + (s[i] - '0');

            if (result*sign > INT_MAX) {
                return INT_MAX;
            }

            if (result*sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        cout<<sign<<endl;
        cout<<result<<endl;
        return (int)(sign * result);
    }
};