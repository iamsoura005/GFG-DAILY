class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> paper;
        paper.push_back(s);
        long long current_sum = s;
        
        for (int i = 0; i < arr.size(); i++) {
            long long next_num = current_sum + arr[i];
            if (next_num > x) {
                break;
            }
            paper.push_back(next_num);
            current_sum += next_num;
        }
        
        long long target = x;
        for (int i = paper.size() - 1; i >= 0; i--) {
            if (target >= paper[i]) {
                target -= paper[i];
            }
        }
        
        return target == 0;
    }
};