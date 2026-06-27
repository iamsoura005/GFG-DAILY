class Solution {
public:
    bool isPrime(int n) {

        // Prime numbers are always greater than 1
        if (n <= 1)
            return false;

        // Check divisibility from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {

            // If i divides n completely,
            // then n has another factor
            if (n % i == 0)
                return false;
        }

        // No divisor found
        return true;
    }
};