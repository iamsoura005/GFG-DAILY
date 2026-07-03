class Solution {
public:
    long long countSubstring(string s) {
        int n = s.length();
        
        // Since max net difference can range from -n to +n, 
        // we use a frequency array shifted by 'n' to avoid negative indexing.
        vector<int> freq(2 * n + 1, 0);
        
        long long ans = 0;
        int current_sum = 0;
        
        // This tracks how many previous prefix sums are strictly LESS than the current_sum
        long long valid_prev_count = 0;
        
        // Initialize for the prefix sum of 0 (before processing any characters)
        freq[0 + n] = 1; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // Moving up by 1 means all previous sums at 'current_sum' 
                // now become strictly less than the new sum.
                valid_prev_count += freq[current_sum + n];
                current_sum++;
            } else {
                // Moving down by 1 means the previous sums at the new 'current_sum'
                // are no longer strictly less than it.
                current_sum--;
                valid_prev_count -= freq[current_sum + n];
            }
            
            ans += valid_prev_count;
            freq[current_sum + n]++;
        }
        
        return ans;
    }
};