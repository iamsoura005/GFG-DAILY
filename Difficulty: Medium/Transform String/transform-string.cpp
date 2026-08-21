class Solution {
public:
    int transform(string &s1, string &s2) {
        if (s1.length() != s2.length()) return -1;

        int count[256] = {0};
        int n = s1.length();

        for (int i = 0; i < n; i++) {
            count[(unsigned char)s1[i]]++;
            count[(unsigned char)s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) return -1;
        }

        int ans = 0;
        int i = n - 1;
        int j = n - 1;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                ans++;
                i--;
            }
        }

        return ans;
    }
};