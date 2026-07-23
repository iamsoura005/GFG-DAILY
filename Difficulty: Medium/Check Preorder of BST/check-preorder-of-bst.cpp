class Solution {
  public:
    bool canRepresentBST(vector<int>& arr) {
        int root = INT_MIN;
        stack<int> s;
        
        for (int x : arr) {
            if (x < root) {
                return false;
            }
            while (!s.empty() && s.top() < x) {
                root = s.top();
                s.pop();
            }
            s.push(x);
        }
        
        return true;
    }
};