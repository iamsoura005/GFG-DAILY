#include <vector>
#include <algorithm>

class Solution {
  public:
    int findMax(int n, std::vector<int>& a, std::vector<int>& b, std::vector<int>& k) {
        int m = a.size();
        
        // Difference array to store boundary markers
        // Using long long for difference values to prevent potential integer overflow during updates
        std::vector<long long> diff(n + 1, 0);

        // Apply difference array updates for all operations
        for (int i = 0; i < m; ++i) {
            int start = a[i];
            int end = b[i];
            int val = k[i];

            diff[start] += val;
            if (end + 1 < n) {
                diff[end + 1] -= val;
            }
        }

        // Calculate prefix sum to find the max element
        long long current_sum = 0;
        long long max_val = 0;

        for (int i = 0; i < n; ++i) {
            current_sum += diff[i];
            max_val = std::max(max_val, current_sum);
        }

        return static_cast<int>(max_val);
    }
};