class Solution {
public:
    int takeCharacters(string s, int k) {

        int n = s.size();

        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        int number = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                cntA++;
            } else if (s[i] == 'b') {
                cntB++;
            } else {
                cntC++;
            }
        }

        if (cntA < k || cntB < k || cntC < k) {
            return -1;
        }

        int i = 0;
        int j = 0;

        while (j < n) {

            if (s[j] == 'a') {
                cntA--;
            } else if (s[j] == 'b') {
                cntB--;
            } else {
                cntC--;
            }

            while (i <= j && (cntA < k || cntB < k || cntC < k)) {
                if (s[i] == 'a') {
                    cntA++;
                } else if (s[i] == 'b') {
                    cntB++;
                } else {
                    cntC++;
                }
                i++;
            }
            number = max(number, j - i + 1);
            j++;
        }

        return n - number;
    }
};