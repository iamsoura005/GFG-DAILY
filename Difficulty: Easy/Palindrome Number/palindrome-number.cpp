class Solution {
public:
    bool isPalindrome(int n) {
        // Take the absolute value to ignore the negative sign
        string s = to_string(abs(n)); 
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        return s == rev;
    }
};