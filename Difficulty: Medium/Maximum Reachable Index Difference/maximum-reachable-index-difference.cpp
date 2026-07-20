class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        int first_a = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                first_a = i;
                break;
            }
        }
        
        if (first_a == -1) return -1;
        
        vector<int> last_pos(26, -1);
        for (int i = 0; i < n; i++) {
            last_pos[s[i] - 'a'] = i;
        }
        
        vector<int> min_reach(26, -1);
        min_reach[0] = first_a;
        
        int curr_idx = first_a;
        for (int c = 1; c < 26; c++) {
            int found = -1;
            for (int i = curr_idx + 1; i < n; i++) {
                if (s[i] - 'a' == c) {
                    found = i;
                    break;
                }
            }
            if (found == -1) break;
            min_reach[c] = found;
            curr_idx = found;
        }
        
        int max_diff = -1;
        
        // For 'a' (character 0)
        if (last_pos[0] > last_pos[1]) {
            max_diff = 0;
        }
        
        // For characters 'b' through 'z'
        for (int c = 1; c < 26; c++) {
            if (min_reach[c - 1] == -1) continue;
            
            int next_last = (c + 1 < 26) ? last_pos[c + 1] : -1;
            if (last_pos[c] > min_reach[c - 1] && last_pos[c] > next_last) {
                max_diff = max(max_diff, last_pos[c] - first_a);
            }
        }
        
        return max_diff;
    }
};