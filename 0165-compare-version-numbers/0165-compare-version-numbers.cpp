class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0;
        int j = 0;
        string str1 = "";
        string str2 = "";
        int a;
        int b;

        while (i < n1 || j < n2) {

            while (i<n1 && version1[i] != '.') {
                str1 += version1[i];
                i++;
            }

            while (j< n2 && version2[j] != '.') {
                str2 += version2[j];
                j++;
            }

            a = str1.empty() ? 0 : stoi(str1);
            b = str2.empty() ? 0 : stoi(str2);

            cout << a << endl;
            cout << b << endl;

            i++;
            j++;
            if (a > b) {
                return 1;
            } else if (a < b) {
                return -1;
            }

            str1 = "";
            str2 = "";
        }

        return 0;
    }
};