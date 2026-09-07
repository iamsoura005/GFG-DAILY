#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    int memo[101][105][105];

    int solve(int idx, int inc_val, int dec_val, const vector<int>& arr) {
        if (idx == arr.size()) {
            return 0;
        }
        if (memo[idx][inc_val][dec_val] != -1) {
            return memo[idx][inc_val][dec_val];
        }

        // Option 1: Skip arr[idx] (arr[idx] is outside both subsequences)
        int ans = 1 + solve(idx + 1, inc_val, dec_val, arr);

        // Option 2: Add arr[idx] to the strictly increasing subsequence
        if (arr[idx] > inc_val) {
            ans = min(ans, solve(idx + 1, arr[idx], dec_val, arr));
        }

        // Option 3: Add arr[idx] to the strictly decreasing subsequence
        if (arr[idx] < dec_val) {
            ans = min(ans, solve(idx + 1, inc_val, arr[idx], arr));
        }

        return memo[idx][inc_val][dec_val] = ans;
    }

public:
    int minCount(vector<int>& arr) {
        memset(memo, -1, sizeof(memo));
        // inc_val initialized to 0 (since 1 <= arr[i] <= 100)
        // dec_val initialized to 101
        return solve(0, 0, 101, arr);
    }
};