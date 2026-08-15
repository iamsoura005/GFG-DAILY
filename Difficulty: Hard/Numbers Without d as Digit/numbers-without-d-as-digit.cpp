#include <string>
#include <vector>
#include <functional>

class Solution {
public:
    int countWithout(int n, int d) {
        std::string s = std::to_string(n);
        int len = s.length();
        std::vector<std::vector<std::vector<int>>> dp(len, std::vector<std::vector<int>>(2, std::vector<int>(2, -1)));

        std::function<int(int, int, int)> solve = [&](int pos, int tight, int lead_zero) {
            if (pos == len) {
                return lead_zero == 0 ? 1 : 0;
            }
            if (dp[pos][tight][lead_zero] != -1) {
                return dp[pos][tight][lead_zero];
            }

            int limit = tight ? (s[pos] - '0') : 9;
            int ans = 0;

            for (int i = 0; i <= limit; i++) {
                if (i == d && !(lead_zero && i == 0)) {
                    continue;
                }

                int new_tight = tight && (i == limit);
                int new_lead = lead_zero && (i == 0);

                ans += solve(pos + 1, new_tight, new_lead);
            }
            return dp[pos][tight][lead_zero] = ans;
        };

        return solve(0, 1, 1);
    }
};