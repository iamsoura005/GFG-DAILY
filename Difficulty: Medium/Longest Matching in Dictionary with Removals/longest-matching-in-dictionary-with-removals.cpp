class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        // Precompute character indices in string s for fast subsequence lookup
        vector<vector<int>> pos(26);
        for (int i = 0; i < (int)s.length(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        string result = "";

        for (const string &word : d) {
            int prev = -1;
            bool possible = true;

            for (char ch : word) {
                const vector<int> &idxList = pos[ch - 'a'];
                auto it = upper_bound(idxList.begin(), idxList.end(), prev);
                if (it == idxList.end()) {
                    possible = false;
                    break;
                }
                prev = *it;
            }

            if (possible) {
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};