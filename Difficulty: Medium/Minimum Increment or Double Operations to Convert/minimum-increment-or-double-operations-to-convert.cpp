class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int total_increments = 0;
        int max_doubles = 0;

        for (int x : arr) {
            int doubles = 0;
            while (x > 0) {
                if (x & 1) {
                    total_increments++;
                }
                x >>= 1;
                if (x > 0) {
                    doubles++;
                }
            }
            max_doubles = max(max_doubles, doubles);
        }

        return total_increments + max_doubles;
    }
};