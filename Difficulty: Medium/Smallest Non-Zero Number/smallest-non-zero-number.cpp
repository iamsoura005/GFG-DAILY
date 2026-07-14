class Solution {
public:
    int find(vector<int>& arr) {
        int req = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            req = (req + arr[i] + 1) / 2;
        }
        return req;
    }
};