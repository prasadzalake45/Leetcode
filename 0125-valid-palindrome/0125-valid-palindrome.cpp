class Solution {
public:
   
    bool isPalindrome(string s) {
        // remove non -alphanumeric
        // uppercase-> lowercase
        // make sure bring it as one string and check if it Palindrone

        string str = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = tolower(s[i]);
            if (isalnum(ch)) {
                str.push_back(ch);
            }
        }

        cout << str << endl;
        int n = str.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};