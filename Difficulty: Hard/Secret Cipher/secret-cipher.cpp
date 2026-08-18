class Solution {
public:
    string compress(string &s) {
        int n = s.size();
        if (n == 0) return "";

        // Precompute KMP longest prefix-suffix (LPS) array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            lps[i] = j;
        }

        string result = "";
        int i = n - 1;

        // Traverse backwards to greedily find the largest doubling segments
        while (i >= 0) {
            int len = i + 1;
            if (len % 2 == 0) {
                int half = len / 2;
                int k = lps[i];

                // Reduce k until k <= half
                while (k > half) {
                    k = lps[k - 1];
                }

                if (k == half) {
                    result += '*';
                    i = half - 1;
                    continue;
                }
            }
            result += s[i];
            i--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};