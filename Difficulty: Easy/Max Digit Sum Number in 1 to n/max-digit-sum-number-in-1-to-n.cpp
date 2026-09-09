class Solution {
private:
    int digitSum(long long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int findMax(int n) {
        string s = to_string(n);
        int len = s.length();

        long long bestNum = n;
        int maxSum = digitSum(n);

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue;

            string candidate = s;
            candidate[i] = candidate[i] - 1;
            for (int j = i + 1; j < len; j++) {
                candidate[j] = '9';
            }

            long long val = stoll(candidate);
            int currentSum = digitSum(val);

            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestNum = val;
            } else if (currentSum == maxSum) {
                if (val > bestNum) {
                    bestNum = val;
                }
            }
        }

        return (int)bestNum;
    }
};