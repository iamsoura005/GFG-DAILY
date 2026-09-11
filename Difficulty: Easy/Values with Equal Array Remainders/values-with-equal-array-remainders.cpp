class Solution {
  public:
    int sameMod(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return -1;

        int g = 0;
        for (int i = 1; i < n; ++i) {
            int diff = std::abs(arr[i] - arr[0]);
            g = std::gcd(g, diff);
        }

        if (g == 0) return -1;

        int divisors_count = 0;
        for (int i = 1; 1LL * i * i <= g; ++i) {
            if (g % i == 0) {
                divisors_count++;
                if (i * i != g) {
                    divisors_count++;
                }
            }
        }

        return divisors_count;
    }
};