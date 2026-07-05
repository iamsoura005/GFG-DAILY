class Solution {
 public:
    int maxCharGap(string &s) {
        // Array to store the first occurrence index of each character 'a' through 'z'
        // Initialize all values with -1 to indicate they haven't been seen yet
        vector<int> firstIndex(26, -1);
        int maxGap = -1;
        
        for (int i = 0; i < s.length(); i++) {
            int charIdx = s[i] - 'a'; // Convert character to 0-25 index
            
            if (firstIndex[charIdx] == -1) {
                // First time seeing this character, record its index
                firstIndex[charIdx] = i;
            } else {
                // Character seen before, calculate the number of characters in between
                int gap = i - firstIndex[charIdx] - 1;
                maxGap = max(maxGap, gap);
            }
        }
        
        return maxGap;
    }
};