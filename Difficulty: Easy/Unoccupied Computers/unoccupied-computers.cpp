class Solution {
public:
    int solve(int n, string s) {
        // State for each customer: 0 = not seen, 1 = using computer, 2 = rejected
        vector<int> status(26, 0);
        int occupied = 0;
        int rejected = 0;

        for (char ch : s) {
            int id = ch - 'A';
            if (status[id] == 0) {
                if (occupied < n) {
                    occupied++;
                    status[id] = 1;
                } else {
                    status[id] = 2;
                    rejected++;
                }
            } else if (status[id] == 1) {
                occupied--;
            }
        }

        return rejected;
    }
};