class Solution {
  public:
    bool isPalindrome(int n) {
        // Take the absolute value to ignore the negative sign as per problem requirements
        n = abs(n);

        // Convert number into string
        string s = to_string(n);

        // Two pointers
        int left = 0;
        int right = s.length() - 1;

        // Compare characters from both ends
        while (left < right) {
            if (s[left] != s[right]) // If characters don't match
                return false;

            left++;  // Move left pointer forward
            right--; // Move right pointer backward
        }

        return true; // All characters matched
    }
};